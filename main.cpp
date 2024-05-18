#include <iostream>

#include "FileIO.h"
#include "PokerHands.h"

int main(int argc, char **argv) {
  PokerHands pokerHands;
  pokerHands.openFiles(argc, argv);

  while (pokerHands.getHands()) {
    pokerHands.compareHands();
    pokerHands.printWinner();
  }

  return 0;
}