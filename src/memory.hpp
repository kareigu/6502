#pragma once

#include <cstdint>


#define Byte uint8_t
#define Bit bool
#define WORD uint16_t

#define RAM_SIZE 40969

struct Memory {
  Byte mem[RAM_SIZE];

  void init_ram();
};
