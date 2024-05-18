#ifndef _HANDS_H_
#define _HANDS_H_

#include <iostream>
#include <fstream>

const int NUM_CARDS_IN_HAND = 5;

struct Card {
  char suit;
  int value;
};

struct Hand {
  struct Card cards[NUM_CARDS_IN_HAND];

  void printHand (void) {
    for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
      std::cout << cards[i].value << "." << cards[i].suit << " ";
    }
    std::cout << std::endl;
  }
};


#endif