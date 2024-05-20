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

  int isHighCard (struct Hand *);
  int isOnePair (struct Hand *);

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