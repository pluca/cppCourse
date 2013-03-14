#ifndef PP6_IO_HH
#define PP6_IO_HH 

#include <string>
#include <cmath>
#include "physClasses.h"
#include "partClasses.h"
#include <vector>
#include <climits>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;


vector< Particle > readFile(string name);

FourVector* createRndm4Vector( int seed );

FourVector* create4Vector(  const double t, const double x, const double y, const double z );

void delete4Vector( FourVector * v );

FourVector* type4Vector();

ParticleInfo FillPartInfo( string name );

//This functions allows to safely enter a value from standard output

template <typename T>
T SafeCin()
{	
  T val;
  
  do{
    cin >> val;
    if(cin.fail()) cout << "\aNot a number, retry!" << endl;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    
  }while(cin.fail());
  
  return val;
}

#endif
