#include "pc.hpp"
#include "cpu.hpp"
#include "asmb.hpp"


void test_prg(CPU* cpu) {
  for (ADDR i = SCREEN_RAM_START; i < SCREEN_RAM_END; i += BYTES_PER_CHARACTER) {
    const ADDR addr = SCREEN_RAM_START;
    asmb::ldx(cpu, i);
    asmb::inx(cpu);
    asmb::stx(cpu, i);
  }
}

void run_update(PC* pc) {
  while (pc->running) {
    pc->cpu.P++;
    test_prg(&pc->cpu);
    //cpu->mem->fill_screen_ram(cpu->PC);
    if (pc->screen_on)
      pc->screen.PostEvent(ftxui::Event::Custom);

    std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_TIME));
  }
}

PC::PC() {
	cpu = CPU();
}

PC::~PC() {
  screen_on = false;
  running = false;
  worker.join();
  delete& cpu;
  delete& screen;
}

void PC::run() {
  running = true;
  worker = std::thread(run_update, this);

  auto screen_draw = cpu.render_screen(&screen_on, &running);

  screen.Loop(screen_draw);
}