#include <sstream>
#include "FileReader.hpp"

FileReader::FileReader(const char* filename)
  : file(filename), line(), isValid_(true)
{}

FileReader::FileReader(const std::string& filename)
  : file(filename.c_str()), line(), isValid_(true)
{}  

bool FileReader::isValid() const {
  if ( ! file )
    return false;
  else
    return true;
}

bool FileReader::nextLine(){
  getline(file, line);
  if (file.eof())
    return false;
  else 
    return true;
}

void FileReader::skip_fields(std::istringstream& ist, const int n) {
  if (n < 1)
    return;
  std::string tmp;
  for(int i = 1; i <= n; ++i) {
    ist >> tmp;
  }
}

bool FileReader::inputFailed() const {
  return !isValid_;
}

