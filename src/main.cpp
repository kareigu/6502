#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

int main() {
  Memory ram;
  CPU cpu = CPU(&ram);

  cpu.print_registers();

  return EXIT_SUCCESS;
}
