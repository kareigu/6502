#include "memory.hpp"
#include <iostream>

void Memory::init_ram() {
  for (int i = 0; i < RAM_SIZE; i++)
    mem[i] = 0x0;

  std::cout << "RAM Initialised with " << RAM_SIZE << " bytes" << std::endl;
}
