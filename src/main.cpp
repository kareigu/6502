#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "memory.hpp"
#include "cpu.hpp"
#include "pc.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"
#include "fmt/core.h"
#include "asmb.hpp"



int main() {
  PC pc = PC();

  pc.run();

  delete& pc;
  return EXIT_SUCCESS;
}
