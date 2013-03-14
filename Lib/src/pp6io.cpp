#include <iostream>
#include <climits>
#include <string>
#include <vector>

#include "pp6io.h"
#include "FileReader.hpp"
#include "physClasses.h"
#include "partClasses.h"

using namespace std;


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
	    f.getField<int>(1);
	    
	    string name = f.getField<string>(2);
	    
	    double px = f.getField<double>(3);
	    double py = f.getField<double>(4);
	    double pz = f.getField<double>(5);
      
	    f.getField<string>(6);
	    
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
  double t = SafeCin<double>();
  cout << "\nx = ";	
  double x = SafeCin<double>();
  cout << "\ny = ";		
  double y = SafeCin<double>();
  cout << "\nz = ";
  double z = SafeCin<double>();
  cout << endl;
  
  FourVector *res = new FourVector( t, x, y, z );
  
  return res;
}




ParticleInfo FillPartInfo(string name)
{
      ParticleInfo pInfo;
      
      FileReader f(name);
      
      if (f.isValid()) 
      {
	f.nextLine();  //jump first line
	
	while (f.nextLine()) 
	{
	  //cout << f.getField<string>(1) <<" "<<  f.getField<int>(2) <<" "<<  f.getField<int>(3) <<" "<<  f.getField<double>(4) << endl;
	  pInfo.insert( f.getField<string>(1), f.getField<int>(2), f.getField<int>(3), f.getField<double>(4) );
	  if (f.inputFailed()) break;
	}
      }

      return pInfo;
}





