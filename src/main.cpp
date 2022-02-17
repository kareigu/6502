#include <iostream>
#include <thread>
#include <chrono>
#include "pc.hpp"


int main() {
  PC pc = PC();

  pc.cpu.reset();
  pc.run();

  delete& pc;
  return EXIT_SUCCESS;
}
