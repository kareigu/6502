#include "cpu.hpp"
#include <iostream>

CPU::CPU(Memory* memory) 
  : mem(memory) 
{
  mem->init_ram();
  std::cout << "CPU Initialised" << std::endl;
}
