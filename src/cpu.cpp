#include "cpu.hpp"
#include <iostream>

CPU::CPU(Memory* memory) 
  : mem(memory) 
{
  mem->init_ram();
  std::cout << "CPU Initialised" << std::endl;
}


static void print_register(const char* label, Byte byte) {
  std::cout << label << ": " << byte << std::endl;
}

static void print_register(const char* label, Bit bit) {
  std::cout << label << ": " << bit << std::endl;
}

static void print_register(const char* label, WORD word) {
  std::cout << label << ": " << word << std::endl;
}

void CPU::print_registers() {
  print_register("Accumulator", A);
  print_register("X", X);
  print_register("Y", Y);

  std::cout << "Status Flags:" << std::endl;
  print_register("N", N);
  print_register("V", V);
  print_register("-", false);
  print_register("B", B);
  print_register("D", D);
  print_register("I", I);
  print_register("Z", Z);
  print_register("C", C);

  print_register("Stack Pointer", S);
  print_register("Program Counter", PC);
}
