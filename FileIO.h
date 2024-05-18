#ifndef _FILE_IO_H_
#define _FILE_IO_H_

#include <fstream>
#include <iostream>
#include <string>

#include "Hands.h"

class FileIO {
  std::ifstream inFile;
  std::ofstream outFile;

  void testArgc(int);
  void openInFile(const char *);
  void openOutFile(const char *);

  int valueToInt (char);
  char valueToChar (int);

  bool getCard(struct Card *);
  bool getHand(struct Hand *);

public:
  FileIO() {};
  FileIO(int argc, char **argv) {
    testArgc(argc);
    openInFile(argv[1]);
    openOutFile(argv[1]);
  };
  ~FileIO() {
    inFile.close();
    outFile.close();
  };
  void openFiles (int argc, char **argv);

  bool getHands (struct Hand *, struct Hand *);
  void printWinner (enum winner);
};

#endif