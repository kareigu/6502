#pragma once
#include <cstdint>

#define RAM_SIZE 64

struct Memory {
  uint8_t mem[RAM_SIZE];

  void init_ram();
};
