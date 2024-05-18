#ifndef _POKER_HANDS_H_
#define _POKER_HANDS_H_

#include "FileIO.h"
#include "Hands.h"
#include "Rank.h"


class PokerHands {
  FileIO fileIO;

  struct Hand whiteHand;
  struct Hand blackHand;

  enum winner win;


public:
  PokerHands() {};
  ~PokerHands() {};

  void openFiles (int, char **);

  bool getHands (void);
  void compareHands (void);
  void printWinner (void);
};

#endif