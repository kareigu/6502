#pragma once

#include <string>
#include <array>
#include "cpu.hpp"
#include "memory.hpp"

namespace asmb {
  void ldx(CPU* cpu, ADDR addr);
  void ldx(CPU* cpu, Byte value);
  void stx(CPU* cpu, ADDR addr);
  void inx(CPU* cpu);
}

namespace INS {
  class Instruction {
  public:
    virtual uint8_t op_code() { return 0; };
    virtual uint8_t cycles() { return 0; };
    virtual void execute(CPU* cpu) { return; };
  };

  class LDA_IM : public Instruction {
  public:
    uint8_t op_code() override { return 0xa9; };
    uint8_t cycles() override { return 2; };
    void execute(CPU* cpu) override;
  };
}

struct INS_SET {
private:
  static const int size = 1;
  static std::array<INS::Instruction*, size> list;

public:

  static std::array<INS::Instruction*, size> get() { return list; }
};

//INS::Instruction* INS_SET[1] = {
//  new INS::LDA_IM() 
//};