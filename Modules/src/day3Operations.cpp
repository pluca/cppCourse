#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

#include "pp6Math.h"
#include "pp6io.h"
#include "physClasses.h"
#include "day3Operations.h"
#include "FileReader.hpp"

int day3Interface()
{
  
  cout << "\nOk, now you can choose the following operations:" << endl;
  cout << "'1' to boost one 4-vector" << endl;
  cout << "'2' to calculate the interval of one 4-vector" << endl;
  cout << "\n>> ";
  
  int choice = SafeCin<int>();
  
  switch(choice)
  {
    
    case 1:
    {     
      cout << "\n***********************\n\nAhhh so you want to boost one 4-vector today, nice! Then type:" << endl;
      cout << "'1' to type in your 4-vector" << endl;
      cout << "'2' to generate a random one" << endl;
      cout << "\n>> ";
      
      int choice2 = SafeCin<int>();
      
      
      FourVector * v4;
      
      if(choice2 == 1)
	v4 = type4Vector();
      else
	v4 = createRndm4Vector(1);
      
      cout << "Ok I got your 4-vector, I'll boost it along the z axis. Now give me the velocity in c=1 units (v in [0,1]):\nvz = ";
      
      double v = SafeCin<double>();
      
      cout << "\nYour original 4-vecotor is: ";
      v4->coutComp();
      
      v4->boost_z(v);
    
      cout << "\nBoosted it becomes: ";
      v4->coutComp();
      cout << endl;
      
      return 0;
    }
    
    
    case 2:
    {
      cout << "\n***********************\n\nOk I will calculate the iterval of your 4-vector! Then type:" << endl;
      cout << "'1' to type in your 4-vector" << endl;
      cout << "'2' to generate a random one" << endl;
      cout << "\n>> ";
      
      int choice2 = SafeCin<int>();
      
      FourVector * v4;
      
      if(choice2 == 1)
	v4 = type4Vector();
      else
	v4 = createRndm4Vector(1);
      
      cout << "\nYour 4-vecotor is: ";
      v4->coutComp();
      
      double intv = v4->interval();
      
      cout << "\nAnd it's interval is: " << intv << endl;
      
      delete v4;
      
      return 0;
    }
    
    default: return 1;
  }
}
  
  
  