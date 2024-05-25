#ifndef _HANDS_H_
#define _HANDS_H_

#include <iostream>
#include <fstream>
#include <iomanip>

const int NUM_SUITS = 4;
enum SUIT {CLUBS, DIAMONDS, HEARTS, SPADES};

const int NUM_VALUES = 13;
enum VALUE {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct Card {
  SUIT suit;
  VALUE value;
};

const int NUM_CARDS_IN_HAND = 5;

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

enum winner {
  WHITE, BLACK, TIE
};

#endif