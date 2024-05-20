#include "PokerHands.h"

void PokerHands::openFiles (int argc, char **argv) {
  fileIO.openFiles(argc, argv);
}


struct DeckRank PokerHands::isHighCard (struct Hand *h) {
  struct DeckRank ret;
  
  ret.active = true;
  ret.rank = HIGH_CARD;
  
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    ret.highCard.push_back(h->cards[i].value);
  }

  sort(ret.highCard.begin(), ret.highCard.end(), std::greater<int>());
  
  return (ret);
}
struct DeckRank PokerHands::isOnePair (struct Hand *h) {
  // Initialize vector - value counter
  std::vector<int> valueCounter;
  for (int i = 0; i < NUM_VALUES; i++) {
    valueCounter.push_back(0);
  }

  // Populate vector - number of each value 
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    valueCounter[h->cards[i].value]++;
  }

  // Find pair
  struct DeckRank ret;
  for (auto it = valueCounter.begin(); it != valueCounter.end(); it++) {
    if (*it == 2) {
      ret.active = true;
      ret.rank = PAIR;

      // Compute card order
      int index = std::distance(valueCounter.begin(), it);
      ret.highCard.push_back(index);
      ret.highCard.push_back(index);
      for (auto jt = valueCounter.begin(); jt != valueCounter.end(); jt++) {
        if (it == jt) continue;
        for (int i = 0; i < *jt; i++) {
          index = std::distance(valueCounter.begin(), jt);
          ret.highCard.push_back(index);
        }
      }
      sort(ret.highCard.begin() + 2, ret.highCard.end(), std::greater<int>());
    }
  }
  return (ret);
}
struct DeckRank PokerHands::isTwoPair (struct Hand *h) {
  // Initialize vector - value counter
  std::vector<int> valueCounter;
  for (int i = 0; i < NUM_VALUES; i++) {
    valueCounter.push_back(0);
  }

  // Populate vector - number of each value 
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    valueCounter[h->cards[i].value]++;
  }

  struct DeckRank ret;
  bool pair1 = false;
  bool pair2 = false;
  
  // Find pairs
  for (auto it = valueCounter.end(); it != valueCounter.begin(); it--) {
    int index;
    
    // Pair1
    if (*it == 2) { 
      if (pair1 == false) {
        pair1 = true;
        index = std::distance(valueCounter.begin(), it);
        ret.highCard.push_back(index);
        ret.highCard.push_back(index);
      }
      // Pair2
      else {
        pair2 = true;
        index = std::distance(valueCounter.begin(), it);
        ret.highCard.push_back(index);
        ret.highCard.push_back(index);
      }
    }
  }
  for (auto it = valueCounter.end(); it != valueCounter.begin(); it--) {
    int index = std::distance(valueCounter.begin(), it);
    if (*it == 1) ret.highCard.push_back(index);
  }
  return ret;
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