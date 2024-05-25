#ifndef _HANDS_H_
#define _HANDS_H_

#include <iostream>
#include <fstream>
#include <iomanip>

const int NUM_SUITS = 4;

enum winner {
  WHITE, BLACK, TIE
};

const int NUM_CARDS_IN_HAND = 5;

struct Card {
  char suit; // C, D, H, S
  int value; // 2 - 13
};

struct Hand {
  struct Card cards[NUM_CARDS_IN_HAND];

  void printHand (void) {
    for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
      std::cout << std::setw(2) << cards[i].value << ".";
      std::cout << cards[i].suit << " ";
    }
    std::cout << std::endl;
  }
};


#endif