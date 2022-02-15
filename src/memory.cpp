#include "memory.hpp"
#include "fmt/core.h"

void Memory::set_byte(ADDR addr, Byte byte) {
  mem[addr] = byte;
}

void Memory::fill_screen_ram(char c) {
  for (int i = SCREEN_RAM_START; i < SCREEN_RAM_END; i += BYTES_PER_CHARACTER) {
    mem[i] = c;
  }
  fmt::print("Screen RAM Initialised with {} bytes\n", SCREEN_RAM_END - SCREEN_RAM_START);
}

void Memory::init_ram() {
  for (int i = 0; i < RAM_SIZE; i++)
    mem[i] = 0x0;

  fmt::print("RAM Initialised with {} bytes\n", RAM_SIZE);

  fill_screen_ram('B');
}
