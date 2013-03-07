#ifndef PP6_IO_HH
#define PP6_IO_HH 

#include <string>
#include <cmath>
#include "physClasses.h"

using namespace std;

int SafeCinNum();

double SafeCinDouble();

vector< Particle > readFile(string name);

#endif
