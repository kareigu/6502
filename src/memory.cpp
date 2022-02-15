#include "memory.hpp"
#include "fmt/core.h"

void Memory::init_ram() {
  for (int i = 0; i < RAM_SIZE; i++)
    mem[i] = 0x0;

  fmt::print("RAM Initialised with {} bytes\n", RAM_SIZE);
}
