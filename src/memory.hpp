#pragma once

#include <cstdint>
#include <memory>


#define Byte uint8_t
#define Bit bool
#define WORD uint16_t
#define ADDR uint16_t

#define RAM_SIZE 40969
#define RESET_VECTOR RAM_SIZE - 2

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 25
#define BYTES_PER_CHARACTER 2
#define SCREEN_RAM_START RAM_SIZE / 2
#define SCREEN_RAM_END SCREEN_RAM_START + (SCREEN_WIDTH * SCREEN_HEIGHT) * BYTES_PER_CHARACTER

struct Memory {
  std::shared_ptr<Byte[]> mem = std::make_shared<Byte[RAM_SIZE]>();

  void init_ram();
  void fill_screen_ram(char c);

  void set_byte(ADDR addr, Byte byte);

  Byte operator[] (uint16_t i) const { return mem[i]; }
  Byte& operator[] (uint16_t i) { return mem[i]; };
};
