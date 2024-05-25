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

  if (pair1 && pair2) {
    ret.active = true;
    ret.rank = TWO_PAIR;
  }
  
  return ret;
}

struct DeckRank PokerHands::isThreeOfAKind (struct Hand *h) {
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
  ret.active = false;
  
  // Find three of a kind
  for (auto it = valueCounter.begin(); it != valueCounter.end(); it++) {
    if (*it == 3) {
      ret.active = true;
      ret.rank = THREE_OF_A_KIND;
      
      int index = std::distance(valueCounter.begin(), it);
      ret.highCard.push_back(index);
      ret.highCard.push_back(index);
      ret.highCard.push_back(index);
    }
    for (auto jt = valueCounter.begin(); jt != valueCounter.end(); jt++) {
      if (it == jt) continue;
      else {
        if (*it == 2) {
          int index = std::distance(valueCounter.begin(), it);
          ret.highCard.push_back(index);
          ret.highCard.push_back(index);
        }
        if (*it == 1) {
          int index = std::distance(valueCounter.begin(), it);
          ret.highCard.push_back(index);
        }
      }
    }
  }
  // Sort lower 2 cards - descending
  sort(ret.highCard.begin() + 3, ret.highCard.end(), std::greater<int>());

  return ret;
}
struct DeckRank PokerHands::isStraight (struct Hand *h) {

  struct DeckRank ret;
  ret.active = false;
  ret.rank = STRAIGHT;

  // Copy hand to highCard vector
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    ret.highCard.push_back(h->cards[i].value);
  }

  // Find straight
  // 1. Sort cards - descending
  // 2. Check no duplicates
  // 3. if (card1 - card5 == 4)) => straight

  // 1.
  sort(ret.highCard.begin(), ret.highCard.end(), std::less<int>());

  // 2.
  bool noDuplicates = true;
  for (auto it = ret.highCard.begin(); it != ret.highCard.end() - 1; it++) 
    if (*it == *(it + 1)) noDuplicates = false;

  // 3.
  if (noDuplicates && ret.highCard[0] - ret.highCard[4] == 4)
    ret.active = true;

  return ret;
}

struct DeckRank PokerHands::isFlush (struct Hand *h) {
  // Initialize ret
  struct DeckRank ret;
  ret.active = false;
  ret.rank = FLUSH;

  // Initialize suit vector
  std::vector<int> suitVector;
  for (int i = 0; i < NUM_SUITS; i++) {
    suitVector.push_back(0);
  }

  // Populate suit vector - number of each suit
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    suitVector[h->cards[i].suit]++;
  }

  // Determine if flush
  for (auto it = suitVector.begin(); it != suitVector.end(); it++) {
    if (*it == NUM_CARDS_IN_HAND)
      ret.active = true;
  }

  // Compute HighCard
  // 1. copy card values to highCard vector
  // 2. sort highCard vector descending

  // 1. 
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    ret.highCard.push_back(h->cards[i].value);
  }
  // 2.
  sort(ret.highCard.begin(), ret.highCard.end(), std::greater<int>());

  return ret;
}
struct DeckRank PokerHands::isFullHouse (struct Hand *h) {
  // Initialize DeckRank
  struct DeckRank ret;
  ret.active = false;
  ret.rank = FULL_HOUSE;

  // Initialize vector - value counter
  std::vector<int> valueCounter;
  for (int i = 0; i < NUM_VALUES; i++) {
    valueCounter.push_back(0);
  }

  // Populate vector - number of each value
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    valueCounter[h->cards[i].value]++;
  }

  // Find full house
  bool isThree = false;
  bool isPair = false;
  int threeVal = 0;

  for (auto it = valueCounter.begin(); it != valueCounter.end(); it++) {
    if (*it == 3) {
      isThree = true;
      threeVal = std::distance(valueCounter.begin(), it);
    }
    if (*it == 2) isPair = true;
  }

  // Compute highCard
  if (isThree && isPair) {
    ret.active = true;

    ret.highCard.push_back(threeVal);
    for (int i = 0; i < 4; i++) 
      ret.highCard.push_back(0);
  }

  return ret;
}
struct DeckRank PokerHands::isFourOfAKind (struct Hand *h) {
  // Initialize ret
  struct DeckRank ret;
  ret.active = false;

  // Initialize vector - value counter
  std::vector<int> valueCounter;
  for (int i = 0; i < NUM_VALUES; i++) {
    valueCounter.push_back(0);
  }

  // Populate vector - number of each value
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    valueCounter[h->cards[i].value]++;
  }

  // Determine if Four of a Kind
  for (auto it = valueCounter.begin(); it != valueCounter.end(); it++) {
    if (*it == 4) {
      ret.active = true;
      ret.rank = FOUR_OF_A_KIND;
      ret.highCard.push_back(std::distance(valueCounter.begin(), it));
      for (int i = 0; i < 4; i++)
        ret.highCard.push_back(0);
    }
  }

  return ret;
}
struct DeckRank PokerHands::isStraightFlush (struct Hand *h) {
  // Initialize ret
  struct DeckRank ret;
  ret.active = false;

  struct DeckRank straight = isStraight(h);
  struct DeckRank flush = isFlush(h);

  if (straight.active && flush.active) {
    ret.active = true;
    ret.rank = STRAIGHT_FLUSH;
    ret.highCard = straight.highCard;
  }

  return ret;
}

struct DeckRank PokerHands::getDeckRank (struct Hand *h) {
  struct DeckRank ret;

  ret = isStraightFlush(h);
  if (ret.active) return ret;

  ret = isFourOfAKind(h);
  //if (ret.active) return ret;

  //ret = isFullHouse(h);
  //if (ret.active) return ret;

  //ret = isFlush(h);
  //if (ret.active) return ret;
    
  //ret = isStraight(h);
  //if (ret.active) return ret;

  //ret = isThreeOfAKind(h);
  //if (ret.active) return ret;

  //ret = isTwoPair(h);
  //if (ret.active) return ret;

  //ret = isOnePair(h);
  //if (ret.active) return ret;

  //ret = isHighCard(h);
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