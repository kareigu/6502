#include "memory.hpp"
#include "fmt/core.h"

void Memory::init_ram() {
  for (int i = 0; i < RAM_SIZE; i++)
    mem[i] = 0x0;

  fmt::print("RAM Initialised with {} bytes\n", RAM_SIZE);

  for (int i = SCREEN_RAM_START; i < SCREEN_RAM_END; i += BYTES_PER_CHARACTER) {
    mem[i] = 'A';
  }
  fmt::print("Screen RAM Initialised with {} bytes\n", SCREEN_RAM_END - SCREEN_RAM_START);
}
