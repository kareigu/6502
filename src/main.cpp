#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"
#include "fmt/core.h"
#include "asmb.hpp"

#define WAIT_TIME 50


void test_prg(CPU* cpu) {
  for(ADDR i = SCREEN_RAM_START; i < SCREEN_RAM_END; i += BYTES_PER_CHARACTER) {
    const ADDR addr = SCREEN_RAM_START;
    asmb::ldx(cpu, i);
    asmb::inx(cpu);
    asmb::stx(cpu, i);
  }
}

void run_update(bool* run, bool* screen_on, CPU* cpu, ftxui::ScreenInteractive* screen) {
  while(*run) {
    cpu->PC++;
    test_prg(cpu);
    //cpu->mem->fill_screen_ram(cpu->PC);
    if(*screen_on)
      screen->PostEvent(ftxui::Event::Custom);

    std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_TIME));
  }
}


int main() {
  CPU cpu = CPU();

  bool run = true;
  bool screen_on = false;

  auto screen = ftxui::ScreenInteractive::Fullscreen();

  std::thread t1(
    run_update, 
    &run, 
    &screen_on, 
    &cpu, 
    &screen
  );

  screen.Loop(cpu.render_screen(&screen_on));

  screen_on = false;
  run = false;
  t1.join();

  return EXIT_SUCCESS;
}
