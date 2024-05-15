#ifndef _HANDS_H_
#define _HANDS_H_

#include <fstream>

const int NUM_CARDS_IN_HAND = 5;

struct Card {
  char suit;
  int value;
};

struct Hand {
  struct Card cards[NUM_CARDS_IN_HAND];
};

#endif