#pragma once

#include "memory.hpp"


struct CPU {
  Memory* mem;
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
  WORD PC;


  CPU(Memory* memory);
};
