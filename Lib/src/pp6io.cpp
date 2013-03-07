#include <iostream>
#include <climits>
#include <string>
#include <vector>

#include "pp6io.h"
#include "FileReader.hpp"
#include "physClasses.h"

using namespace std;

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