#include <iostream>
#include "memory.hpp"
#include "cpu.hpp"

int main() {
  Memory ram;
  CPU cpu = CPU(&ram);

  cpu.print_registers();
  return 0;
}
