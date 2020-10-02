#include <iostream>
#include <thread>

void test() {
  std::cout << "hello" << std::endl;
}

void functionA() {
  std::thread threadC(test);
  threadC.join();
}

void functionB() {
}

int main() {
  std::thread threadA(functionA);
  threadA.join();
  std::thread threadB(functionB);
  threadB.join();
  // Order:
  // - threadA
  // - threadC
  // - threadB
  // - main
  return 0;
}
