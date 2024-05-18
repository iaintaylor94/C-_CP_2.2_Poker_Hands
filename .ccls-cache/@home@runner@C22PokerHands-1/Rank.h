#ifndef _RANK_H_
#define _RANK_H_



enum Rank {
  HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH
};

struct DeckRank {
  enum Rank rank;
  int highCard;
};

#endif