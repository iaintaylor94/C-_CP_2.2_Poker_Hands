#include <iostream>

#include "FileIO.h"

int main(int argc, char **argv) {
  FileIO fileIO;
  fileIO.openFiles(argc, argv);

  return 0;
}