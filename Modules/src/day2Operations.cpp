#include <cmath>
#include <vector>
#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

#include "pp6Math.h"
#include "pp6io.h"
#include "day2Operations.h"
#include "FileReader.hpp"

int day2Interface()
{
  
  cout << "\nOk man now you can choose the following operations:" << endl;
  
  cout << "'1' to swap two numbers (how exiting eh...!!!)" << endl;
  cout << "'2' for sorting arrays" << endl;
  cout << "'3' generate and study energies" << endl;
  cout << "'4' analyise ObservedParticles.dat (not implemented yet)" << endl;
  cout << "\n>> ";
  
  int choice = SafeCinNum();
  
  switch(choice)
  {
    
    case 1:
    {
      double a, b;
      
      cout << "Insert two numbers" << endl;
      
      a = SafeCinDouble();
      b = SafeCinDouble();
      
      cout << "You inserted: " << a << "    " << b << endl;
      
      swap(a,b);
      
      cout << "And now I swap them: " << a << "    " << b << endl;
      
      return 0;
    }
    
    
    case 2:
    {
      cout << "\n***********************\n\nI'll sort an arrey of N numbers." << endl;
      cout << "How many numbers do you want? N = ";
      int N = SafeCinNum();
      
      double * v = new double[N]; 
      
      for(int i = 0; i < N; i++)
      {	
	cout << "\nGive me the number " << i+1 << ": ";			
	v[i] = SafeCinDouble();
      }
      
      cout << "\nType '1' if you want it in increasing order (anything else will give you decreasing)" << endl;
      
      if(SafeCinNum() == 1) sort(v,N,false);
      else sort(v,N);
      
      cout << "\nYour vector sorted is:\n " << endl; 
      for(int i = 0; i < N; i++) cout << v[i] << ", ";
      cout << endl;
      
      return 0;
    }
    
    
    case 3:
    {
      cout << "\n***********************\n\nI'll now generare 100 random energies." << endl;
      cout << "\n\t- Momentum components generated in [-10,+10] GeV" << endl;
      cout << "\t- Masses generated in [0,100] GeV\n" << endl;    
     
      const int N = 100;
      double E[N];
      
      for(int i = 0; i < N; i++)
      {
	//Momentum components generated between -10 and 10 GeV
	
	srand (i);
	double px = rand()%20000 - 10000;

	srand (i+N);
	double py = rand()%20000 - 10000;
	
	srand (i+2*N);
	double pz = rand()%20000 - 10000;
	
	srand (i+3*N);
	double m = rand()%100000;
	
	E[i] = sqrt(m*m + px*px + py*py + pz*pz);
      }
      
      
      cout << "\nThe average of my energy distribution is: " << average(E,100) << endl;
      cout << "The stantard deviation of my energy distribution is: " << sigma(E,100) << endl;
      cout << "The max energy is: " << max(E,100) << endl;   
      
      return 0;
    }
    
    
    case 4:
    {
      cout << "\n***********************\n\nI will now analyse ObservedParticles.dat" << endl;
    
      vector< Particle > part = readFile("observedparticles.dat");
      if( part.size()==0 ) { cout << "ERROR!! There has been a reading error, I have an empty list of particles!" << endl; return 1; }
      
      vector< Particle > muplus;
      vector< Particle > muminus;
      
      for(unsigned int i = 0; i < part.size(); i++)
      {
	if( part[i].getName() == "mu+" ) muplus.push_back(part[i]);
	else if( part[i].getName() == "mu-" ) muminus.push_back(part[i]);
      }
      
  
      int Ncomb = muplus.size()*muminus.size();
      double * invMasses = new double[Ncomb];
      int cur = 0;
      
      for(unsigned int i = 0; i < muplus.size(); i++)
      {
	for(unsigned int j = 0; j < muminus.size(); j++)
	{
	  FourVector v1 = muplus[i].get4Vector();
	  FourVector v2 = muminus[j].get4Vector();
	  FourVector sum = v1 + v2;
	  invMasses[cur] = sum.interval();
	  cur++;
	}
      }
      
      sort(invMasses, Ncomb);
      
      cout << "The 10 highest invariant masses I found are: \n" << endl;
      for(int i = 0; i < 10; i++) cout << fixed << setprecision(2) << invMasses[i] << " GeV" << endl;
      
      return 0;
    }
    
    default: return 1;
  }
}
  
  
  