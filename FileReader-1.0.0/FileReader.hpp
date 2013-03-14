#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <string>
#include <sstream>

class FileReader {
 public:
  FileReader(const char* filename);
  FileReader(const std::string& filename);

  bool nextLine();

  template < typename T >
  T getField(const int n) {  
    isValid_ = true;
    std::istringstream ist(line);
    this->skip_fields(ist, n-1);
    T rval;
    ist >> rval;
    
    if (ist.fail()) 
      isValid_= false;

    return rval;
  }
  
  bool inputFailed() const;
  bool isValid() const;

 private:
  void skip_fields(std::istringstream& ist, const int n);
  std::ifstream file;
  std::string line;
  bool isValid_;
};

#endif
