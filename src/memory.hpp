#pragma once

#include <cstdint>


#define Byte uint8_t
#define Bit bool
#define WORD uint16_t
#define ADDR uint16_t

#define RAM_SIZE 40969

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 25
#define BYTES_PER_CHARACTER 2
#define SCREEN_RAM_START RAM_SIZE / 2
#define SCREEN_RAM_END SCREEN_RAM_START + (SCREEN_WIDTH * SCREEN_HEIGHT) * BYTES_PER_CHARACTER

struct Memory {
  Byte mem[RAM_SIZE];

  void init_ram();

  Byte operator[] (uint16_t i) const { return mem[i]; }
  Byte& operator[] (uint16_t i) { return mem[i]; };
};
