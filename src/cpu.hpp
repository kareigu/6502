#pragma once

#include "memory.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component.hpp"


struct CPU {
  Memory mem;
  Byte A;
  Byte X;
  Byte Y;

  Bit N;
  Bit V;
  Bit B;
  Bit D;
  Bit I;
  Bit Z;
  Bit C;

  Byte S;
  WORD P;


  CPU();

  ftxui::Element print_registers();
  ftxui::Element print_screen_ram();
  ftxui::Component render_screen(bool* screen_on, bool* running);
};
