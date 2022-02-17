#include "asmb.hpp"
#include "memory.hpp"

namespace asmb {
  void ldx(CPU* cpu, ADDR addr) {
    cpu->X = cpu->mem[addr];
  }

  void ldx(CPU* cpu, Byte value) {
    cpu->X = value;
  }

  void stx(CPU* cpu, ADDR addr) {
    cpu->mem[addr] = cpu->X;
  }

  void inx(CPU* cpu) {
    cpu->X++;
  }


}

namespace INS {
  void LDA_IM::execute(CPU* cpu) {
    auto c = cycles();
    Byte data = cpu->fetch_byte(c);
    cpu->A = data;
    cpu->Z = cpu->A == 0;
    cpu->N = (cpu->A & 0b1000000) > 0;
  }

  void JMP_ABS::execute(CPU* cpu) {
    auto c = cycles();
    WORD data = cpu->fetch_word(c);
    cpu->PC = data;
  }
}


std::array<INS::Instruction*, INS_SET::size> INS_SET::list = {
  new INS::LDA_IM(),
  new INS::JMP_ABS(),
};
