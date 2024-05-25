#include "FileIO.h"

void FileIO::testArgc (int argc) {
  if (argc != 2) std::cerr << "Usage: ./FileIO <filename>" << std::endl;
  else std::cerr << "Usage: number of arguments is correct" << std::endl;
}
void FileIO::openInFile (const char *filename) {
  inFile.open(filename);
  
  if (!inFile.is_open()) std::cerr << "Error: could not open file " << filename << std::endl;
  else std::cerr << "Opened file " << filename << std::endl;
}
void FileIO::openOutFile (const char *filename) {
  std::string fn = filename;
  outFile.open(fn + ".out");

  if (!outFile) std::cerr << "Error: could not open file " << fn << ".out" << std::endl;
  else std::cerr << "Opened file " << fn << ".out" << std::endl;
}

void FileIO::openFiles (int argc, char **argv) {
  testArgc(argc);
  openInFile(argv[1]);
  openOutFile(argv[1]);
}


enum VALUE FileIO::charToVALUE (char valChr) {
  if (valChr == '2') return TWO;
  else if (valChr == '3') return THREE;
  else if (valChr == '4') return FOUR;
  else if (valChr == '5') return FIVE;
  else if (valChr == '6') return SIX;
  else if (valChr == '7') return SEVEN;
  else if (valChr == '8') return EIGHT;
  else if (valChr == '9') return NINE;
  else if (valChr == 'T') return TEN;
  else if (valChr == 'J') return JACK;
  else if (valChr == 'Q') return QUEEN;
  else if (valChr == 'K') return KING;
  else if (valChr == 'A') return ACE;
    
  else std::cerr << "Error: invalid value character " << valChr << std::endl;
  return TWO;
}
enum SUIT FileIO::charToSUIT (char suitChr) {
  if (suitChr == 'C') return CLUBS;
  else if (suitChr == 'D') return DIAMONDS;
  else if (suitChr == 'H') return HEARTS;
  else return SPADES;
}


bool FileIO::getCard (struct Card *c) {
  std::string inC;
  inFile >> inC;

  if (inFile.eof()) return false;
  else {
    c->value = charToVALUE(inC[0]);
    c->suit = charToSUIT(inC[1]);
  }
  return true;
}
bool FileIO::getHand (struct Hand *h) {
  for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
    if (!getCard(&h->cards[i])) return false;
  }
  return true;
}
bool FileIO::getHands (struct Hand *WhiteHand, struct Hand *BlackHand) {
  if (!getHand(WhiteHand)) return false;
  else getHand(BlackHand);
  return true;
}

void FileIO::printWinner(enum winner win) {
  if (win == WHITE) std::cout << "White wins." << std::endl;
  else if (win == BLACK) std::cout << "Black wins." << std::endl;
  else if (win == TIE) std::cout << "Tie." << std::endl;
  else std::cerr << "Error: invalid winner" << std::endl;
}