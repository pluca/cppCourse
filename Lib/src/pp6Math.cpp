#include <cmath>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "pp6Math.h"


using namespace std;

//Performs additions

double add(double a, double b)
{
   return a+b;
}



//Performs subtraction

double subtract(double a, double b)
{
   return a-b;
}



//Performs multiplication

double multiply(double a, double b)
{
   return a*b;
}



//Performs division
//Returns 0 if denominator is two small but gives a warining

double divide(double a, double b)
{
   if(abs(b) > 1e-13 ) return a/b;
   else { cout << "ERROR! Denominator cannot be zero. The function returns 0 but it's not a reasonable result" << endl; return 0; } 
}



//Swapt two numbers

void swap(double &a, double &b)
{
    double tmp = b;
    b = a;
    a = tmp;
}


//Extract roots of a quadratic equation: returns 0 if everything ok
//Returns 1 if roots are imaginary

int extractRoots(double a, double b, double c, double &r1, double &r2)
{
    double delta = pow(b,2) - 4*a*c;
    
    if(delta < 0) return 1;
    else
    {
	r1 = (-b + sqrt(delta))/(2*a);
	r2 = (-b + sqrt(delta))/(2*a);
    }
      
    return 0;
}



//Computes the invariant mass of N particles
//Returns -1 if Etot < |ptot|

double invMass(vector<double> E, vector<double> px, vector<double> py, vector<double> pz)
{
    double Etot = 0, pxtot = 0, pytot = 0, pztot = 0;

    for(unsigned i = 0; i < E.size(); i++)
    {
	Etot += E.at(i);
	pxtot += px.at(i);
	pytot += py.at(i);
	pztot += pz.at(i);
    }			

    double m2 = Etot*Etot - pxtot*pxtot - pytot*pytot - pztot*pztot;
    if(m2 < 0)  return -1;
    else return sqrt(m2);
}



//Computes the invariant mass of 2 particles
//Returns -1 if Etot < |ptot|


double twoPartInvMass(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2)
{
  double m2 = pow(E1+E2,2) - pow(px1+px2,2) - pow(py1+py2,2) - pow(pz1+pz2,2);
  if(m2 < 0)  return -1;
  else return sqrt(m2);
}





//Finds the incercept on x ax of a line (and also on y ax, q, and the angular coefficient, m)
//Returns -1 if line is vertical
//Returns -2 if line is horizontal and therfore has no intercept on x ax.

int findIntercept(double x1, double y1, double x2, double y2, double &m, double &q, double &x0)
{
    if(abs(x1-x2) > 1e-13)
    {
	m = (y2-y1)/(x1-x2);
	q = y1 - m*x1;
	x0 = -y1/m;
	
	if(abs(m) < 1e-13) return -2;
	else return 0;
    }
    else { x0 = x1; return -1; }
  
}




// Computes the lenghts of a vector

double lenght(vector<double> v)
{
    double l2 = 0;
  
    std::vector<double>::iterator iter = v.begin();
    
    for( ; iter != v.end(); ++iter)
    {
	l2 += pow(*iter,2);
    }			

    return sqrt(l2);
}




//Sorts an array on N number in decreasing (default) of increasing order 

vector < double > sort(vector < double > v, bool decreasing)
{
    vector <double> res(v);
  
    bool sorted = false;
  
    while (sorted == false)
    {
	sorted = true;

	for( unsigned i = 1; i < res.size(); ++i )
	{
	    if(res[i-1] < res[i] && decreasing) { swap( res[i] , res[i-1] ); sorted = false; }
	    else if(res[i] < res[i-1] && !decreasing) { swap( res[i] , res[i-1] ); sorted = false; }
	}
    }
  
   return res;
}



//Sorts an array on N number in decreasing (default) of increasing order keeping trak of the new position of the original indices
/*
int sortAndKeepTrack(vector <double> v, vector <int> &indices, bool decreasing)
{
  bool sorted = false;
  
  indices.clear();
  for(unsigned i = 0; i < v.size(); i++) indices.push_back(i);
  
  while (sorted == false)
  {
    sorted = true;
    
    for(unsigned int i = 1; i < v.size(); i++)
    {
	if( (v[i-1] < v[i] && decreasing) || (v[i] < v[i-1] && !decreasing) ) 
	{ 
	  swap( v[i] , v[i-1] );
	  swap(indices[i],indices[i-1]);
	  sorted = false;
	}
    }
  }
  
  return 0;
}
*/



//Computes the average of a vector of doubles

double average(vector <double> v)
{
      double avg = 0;
      
      std::vector<double>::iterator iter = v.begin();
      for( ; iter != v.end(); ++iter) avg+= *iter;
      
      return avg/v.size();
}


//Computes the standars deviation of a vector of doubles

double sigma(vector <double> v)
{
  if(v.size() < 1) { cout << "ERROR! Your vector must have at least 2 components!" << endl; return 0; } 
  
  double sigma = 0;
  double avg = average(v); 
  
  std::vector<double>::iterator iter = v.begin();
  for( ; iter != v.end(); ++ iter) sigma += pow( *iter - avg , 2 );
  
  return sqrt(sigma/v.size());
}


//Finds the maximum of a vector of doubles

double max(vector <double> v)
{
  double max = v[0];
  
  std::vector<double>::iterator iter = v.begin();
  for( ; iter != v.end(); ++iter) 
    if(*iter > max) max = *iter;
  
  return max;
  
}


int RandomNumber () 
{ 
  return (std::rand()%100);
}









