#include <iostream>

#include "FileIO.h"

int main(int argc, char **argv) {
  FileIO fileIO;
  fileIO.openFiles(argc, argv);

  struct Hand whiteHand, blackHand;
  while (fileIO.getHands(&whiteHand, &blackHand)) {
    std::cout << "White hand: " << std::endl;
    std::cout << "Black hand: " << std::endl;
  }

  return 0;
}