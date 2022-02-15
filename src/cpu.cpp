#include "cpu.hpp"
#include "fmt/core.h"

CPU::CPU(Memory* memory) 
  : mem(memory) 
{
  mem->init_ram();
  fmt::print("CPU Initialised\n");
}


static void print_register(const char* label, Byte byte) {
  fmt::print("{}: {:#x}\n", label, byte);
}

static void print_register(const char* label, Bit bit) {
  fmt::print("{}: {:b}\n", label, bit);
}

static void print_register(const char* label, WORD word) {
  fmt::print("{}: {:#x}\n", label, word);
}

void CPU::print_registers() {
  print_register("Accumulator", A);
  print_register("X", X);
  print_register("Y", Y);

  fmt::print("Status Flags:\n");
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
