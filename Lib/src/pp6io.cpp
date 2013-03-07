#include <iostream>
#include <climits>
#include <string>
#include <vector>

#include "pp6io.h"
#include "FileReader.hpp"
#include "physClasses.h"

using namespace std;


//This functions allows to safely eter a int from standard output

int SafeCinNum()
{	
	int number;
	
	do{
		cin >> number;
        	if(cin.fail()) cout << "\aNot a number, retry!" << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');

    	}while(cin.fail());

	return number;
}


//This functions allows to safely eter a double from standard output

double SafeCinDouble()
{	
	double number;
	
	do{
		cin >> number;
        	if(cin.fail()) cout << "\aNot a number, retry!" << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');

    	}while(cin.fail());

	return number;
}




//This functions allows read particles from a file using Filereader library

vector< Particle > readFile(string name)
{
    vector< Particle > res;
  
    FileReader f(name.c_str());
  
    if (f.isValid()) 
    {
      f.nextLine();  //jump first line
      
	while (f.nextLine()) 
	{
	    f.getFieldAsInt(1);
	    
	    string name = f.getFieldAsString(2);
	    
	    double px = f.getFieldAsDouble(3);
	    double py = f.getFieldAsDouble(4);
	    double pz = f.getFieldAsDouble(5);
      
	    f.getFieldAsString(6);
	    
	    if (f.inputFailed()) break;
	    
	    Particle evt(name,px,py,pz);
	    
	    res.push_back(evt);
	}
    }
  
    return res;
}






//This function allows to create a pointer to a random FourVector

FourVector* createRndm4Vector( int seed ) { FourVector *res = new FourVector( seed ); return res; }



//This function allows to delete a pointer to a FourVector

FourVector* create4Vector(  const double t, const double x, const double y, const double z )
{ 
  FourVector *res = new FourVector( t, x, y, z ); return res;
}



//This function allows to crate a pointer to a random FourVector

void delete4Vector( FourVector * v ) { delete v; }


//This function allows to safely type in a FourVector from stantard input

FourVector * type4Vector() 
{ 
  cout << "Give me the 4-vector: \nt = ";		
  double t = SafeCinDouble();
  cout << "\nx = ";	
  double x = SafeCinDouble();
  cout << "\ny = ";		
  double y = SafeCinDouble();
  cout << "\nz = ";
  double z = SafeCinDouble();
  cout << endl;
  
  FourVector *res = new FourVector( t, x, y, z );
  
  return res;
}




