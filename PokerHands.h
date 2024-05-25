#ifndef _POKER_HANDS_H_
#define _POKER_HANDS_H_

#include <vector>
#include <algorithm>

#include "FileIO.h"
#include "Hands.h"
#include "Rank.h"


class PokerHands {
  FileIO fileIO;

  struct Hand whiteHand;
  struct Hand blackHand;

  enum winner win;

  struct DeckRank whiteRank;
  struct DeckRank blackRank;

  struct DeckRank isHighCard (struct Hand *);
  struct DeckRank isOnePair (struct Hand *);
  struct DeckRank isTwoPair (struct Hand *);
  struct DeckRank isThreeOfAKind (struct Hand *);
  struct DeckRank isStraight (struct Hand *);
  struct DeckRank isFlush   (struct Hand *);
  struct DeckRank isFullHouse(struct Hand *);
  struct DeckRank isFourOfAKind(struct Hand *);
  struct DeckRank isStraightFlush(struct Hand *);

  struct DeckRank getDeckRank (struct Hand*);
  enum winner compareRanks (struct DeckRank*, struct DeckRank*);


public:
  PokerHands() {};
  ~PokerHands() {};

  void openFiles (int, char **);

  bool getHands (void);
  void getWinner (void);
  void printWinner (void);
};

#endif