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