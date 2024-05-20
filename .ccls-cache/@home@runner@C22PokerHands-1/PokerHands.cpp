#include "PokerHands.h"

void PokerHands::openFiles (int argc, char **argv) {
  fileIO.openFiles(argc, argv);
}


struct DeckRank isHighCard (struct Hand *h) {
  struct DeckRank ret;
  
  ret.active = true;
  ret.rank = HIGH_CARD;
  
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    ret.highCard.push_back(h->cards[i].value);
  }

  sort(ret.highCard.begin(), ret.highCard.end(), std::greater<int>());
  
  return (ret);
}
int isOnePair (struct Hand *h) {
  // Initialize vector
  const int NUM_VALUES = 12;
  std::vector<int> valueCounter;
  for (int i = 0; i < NUM_VALUES; i++) {
    valueCounter.push_back(0);
  }

  // Populate vector
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    valueCounter[h->cards[i].value]++;
  }

  // Find pair
  for (auto it = valueCounter.begin(); it != valueCounter.end(); it++) {
    if (*it == 2) return (it - valueCounter.begin());
  }
  return (0);
}
int isTwoPair (struct Hand *h) {
  
}

struct DeckRank PokerHands::getDeckRank (struct Hand *h) {
  struct DeckRank ret;

  ret = isStraightFlush(h);
  if (ret.active) return ret;

  ret = isFourOfAKind(h);
  if (ret.active) return ret;

  ret = isFullHouse(h);
  if (ret.active) return ret;

  ret = isFlush(h);
  if (ret.active) return ret;
    
  ret = isStraight(h);
  if (ret.active) return ret;

  ret = isThreeOfAKind(h);
  if (ret.active) return ret;

  ret = isTwoPair(h);
  if (ret.active) return ret;

  ret = isOnePair(h);
  if (ret.active) return ret;

  ret = isHighCard(h);
  return ret;
}
enum winner PokerHands::compareRanks (struct DeckRank *DRW, struct DeckRank *DRB) {
  if (DRW->rank > DRB->rank) return WHITE;
  else if (DRW->rank < DRB->rank) return BLACK;
  else {
    if (DRW->highCard > DRB->highCard) return WHITE;
    else if (DRW->highCard < DRB->highCard) return BLACK;
    else return TIE;
  }
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