#include "PokerHands.h"

void PokerHands::openFiles (int argc, char **argv) {
  fileIO.openFiles(argc, argv);
}

bool PokerHands::getHands () {
  return fileIO.getHands(&whiteHand, &blackHand);
}
void PokerHands::compareHands () {
  
}
void PokerHands::printWinner () {
  fileIO.printWinner(win);
}