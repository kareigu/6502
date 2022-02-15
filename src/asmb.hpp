#pragma once
#include "cpu.hpp"
#include "memory.hpp"

namespace asmb {
  void ldx(CPU* cpu, ADDR addr);
  void ldx(CPU* cpu, Byte value);
  void stx(CPU* cpu, ADDR addr);
  void inx(CPU* cpu);
}
