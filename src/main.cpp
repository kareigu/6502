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
  const ADDR addr = 0x25;
  asmb::ldx(cpu, addr);
  asmb::inx(cpu);
  asmb::stx(cpu, addr);
}

void run_update(bool* run, bool* screen_on, CPU* cpu, ftxui::ScreenInteractive* screen) {
  while(*run) {
    cpu->PC++;
    test_prg(cpu);
    if(*screen_on)
      screen->PostEvent(ftxui::Event::Custom);

    std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_TIME));
  }
}


int main() {
  Memory ram;
  CPU cpu = CPU(&ram);

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
