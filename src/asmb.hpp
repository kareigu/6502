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
  struct Instruction {
    virtual uint8_t op_code() { return 0; };
    virtual uint8_t cycles() { return 0; };
    virtual void execute(CPU* cpu) { return; };
  };

  struct LDA_IM : public Instruction {
    uint8_t op_code() override { return 0xa9; };
    uint8_t cycles() override { return 2; };
    void execute(CPU* cpu) override;
  };

  struct JMP_ABS : public Instruction {
    uint8_t op_code() override { return 0x4c; };
    uint8_t cycles() override { return 3; };
    void execute(CPU* cpu) override;
  };
}

struct INS_SET {
private:
  static const int size = 2;
  static std::array<INS::Instruction*, size> list;

public:

  static std::array<INS::Instruction*, size> get() { return list; }
};

//INS::Instruction* INS_SET[1] = {
//  new INS::LDA_IM() 
//};