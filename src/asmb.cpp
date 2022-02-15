#include "asmb.hpp"
#include "memory.hpp"

namespace asmb {
  void ldx(CPU* cpu, ADDR addr) {
    cpu->X = (*cpu->mem)[addr];
  }

  void ldx(CPU* cpu, Byte value) {
    cpu->X = value;
  }

  void stx(CPU* cpu, ADDR addr) {
    (*cpu->mem)[addr] = cpu->X;
  }

  void inx(CPU* cpu) {
    cpu->X++;
  }
}
