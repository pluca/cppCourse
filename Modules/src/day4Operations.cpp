#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

#include "pp6Math.h"
#include "pp6io.h"
#include "physClasses.h"
#include "day4Operations.h"
#include "FileReader.hpp"

int day4Interface()
{
  typedef std::vector<double> VectDouble;
  
  cout << "\nOk, now you can choose the following operations:" << endl;
  cout << "'1' to analyse new particle file" << endl;
  cout << "'2' to generate and analyse energies" << endl;
  cout << "\n>> ";
  
  int choice = SafeCin<int>();
  
  switch(choice)
  {
    
    case 1:
    {     
      ParticleInfo pInfo = FillPartInfo("pdg.dbt");
      
      //cout << pInfo.getMassGeV("mu+") << endl;
      //cout << pInfo.size() << endl;
      
      vector< Particle > part = readFile("observedparticles.dat");
      if( part.size()==0 ) { cout << "ERROR!! There has been a reading error, I have an empty list of particles!" << endl; return 1; }
      
      vector< Particle > muplus;
      vector< Particle > muminus;
      
      for(unsigned int i = 0; i < part.size(); i++)
      {
	if( part[i].getName() == "mu+" ) 
	  muplus.push_back(part.at(i));
	else if( part[i].getName() == "mu-" ) 
	  muminus.push_back(part.at(i));
      }
      
      //int Ncomb = muplus.size()*muminus.size();
      vector < double > invMasses;
      
      for(unsigned int i = 0; i < muplus.size(); i++)
      {
	for(unsigned int j = 0; j < muminus.size(); j++)
	{
	  FourVector v1 = muplus[i].get4Vector();
	  FourVector v2 = muminus[j].get4Vector();
	  FourVector sum = v1 + v2;
	  invMasses.push_back( sum.interval() );
	}
      }
      
      vector<double> sorted = sort(invMasses);
      
      cout << "The 10 highest invariant masses I found are: \n" << endl;
      for(int i = 0; i < 10; i++) 
	cout << std::fixed << std::setprecision(2) << sorted[i] << " GeV" << endl;
      
      return 0;
    }
    
    case 2:
    {
      VectDouble myvector (10);
      std::generate (myvector.begin(), myvector.end(), RandomNumber);
      
      VectDouble::iterator i = myvector.begin();
      for( ; i != myvector.end(); ++i ) cout << *i << endl;
      
      vector<double> sorted = sort(myvector);
      
      cout << "The maximum is: " << sorted.front() << " and the minimum " << sorted.back() << endl;
      
      i = myvector.begin();
      for( ; i != myvector.end(); ++i ) cout << *i << endl;   
      
      return 0;
    }
    
    default: return 1;
  }
}
  
  
  