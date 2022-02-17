#pragma once

#include "memory.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component.hpp"


struct CPU {
  Memory mem;
  Byte A;
  Byte X;
  Byte Y;

  Bit N = 1;
  Bit V = 1;
  Bit B = 1;
  Bit D = 1;
  Bit I = 1;
  Bit Z = 1;
  Bit C = 1;

  Byte SP;
  WORD PC;


  CPU();

  Byte fetch_byte(uint8_t& cycles_left);

  void reset();

  ftxui::Element print_registers();
  ftxui::Element print_screen_ram();
  ftxui::Component render_screen(bool* screen_on, bool* running);
};
