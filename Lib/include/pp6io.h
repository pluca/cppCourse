#ifndef PP6_IO_HH
#define PP6_IO_HH 

#include <string>
#include <cmath>
#include "physClasses.h"
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;

int SafeCinNum();

double SafeCinDouble();

vector< Particle > readFile(string name);


FourVector* createRndm4Vector( int seed );

FourVector* create4Vector(  const double t, const double x, const double y, const double z );

void delete4Vector( FourVector * v );

FourVector* type4Vector();


#endif
