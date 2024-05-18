#include "PokerHands.h"

void PokerHands::openFiles (int argc, char **argv) {
  fileIO.openFiles(argc, argv);
}


struct DeckRank PokerHands::getDeckRank (struct Hand *h) {
  
}
enum winner PokerHands::compareRanks (struct DeckRank *DRW, struct DeckRank *DRB) {
  
}


bool PokerHands::getHands () {
  return fileIO.getHands(&whiteHand, &blackHand);
}
void PokerHands::getWinner () {
  whiteRank = getDeckRank (&whiteHand);
  blackRank = getDeckRank (&blackHand);
  
  win = compareRanks (&whiteRank, &blackRank);
}
void PokerHands::printWinner () {
  fileIO.printWinner(win);
}