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


int FileIO::valueToInt (char valChr) {
  if (valChr >= '2' && valChr <= '9') return valChr - '0' - 1; // 1 .. 8
  else if (valChr == 'J') return 8;
  else if (valChr == 'Q') return 9;
  else if (valChr == 'K') return 10;
  else if (valChr == 'A') return 11;
  return 0;
}
char FileIO::valueToChar (int val) {
  if (val >= 0 && val <= 7) return val + 1 + '0'; // '2' .. '9'
  else if (val == 8) return 'J';
  else if (val == 9) return 'Q';
  else if (val == 10) return 'K';
  else if (val == 11) return 'A';
  else return 0;
}


bool FileIO::getCard (struct Card *c) {
  std::string inC;
  inFile >> inC;

  if (inFile.eof()) return false;
  else {
    c->value = valueToInt(inC[0]); // Integer needed to rank hands
    c->suit = inC[1];
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