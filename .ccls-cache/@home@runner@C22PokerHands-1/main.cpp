#include <iostream>


#include "PokerHands.h"

int main(int argc, char **argv) {
  PokerHands pokerHands;
  pokerHands.openFiles(argc, argv);

  while (pokerHands.getHands()) {
    pokerHands.getWinner();
    pokerHands.printWinner();
  }

  return 0;
}