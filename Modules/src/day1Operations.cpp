#include <cmath>
#include <vector>
#include <iostream>
#include <climits>

#include "pp6Math.h"
#include "pp6io.h"
#include "day1Operations.h"
	
	
int day1Interface()
{
	  cout << "\nOk, now you can choose the following operations:" << endl;
	  cout << "'0' to perform mathematical operations" << endl;
	  cout << "'1' for finding the intercept" << endl;
	  cout << "'2' for calculating lenghts" << endl;
	  cout << "'3' for calculating invariant masses" << endl;
	  cout << "'4' for solving quadratic equations" << endl;
	  cout << "\n>> ";

	  int choice = SafeCin<int>();
	  
	  switch(choice)
	  {
	    
	    case 0:{
	      
	      if(performMaths()) return 1;
	      
	      return 0;
	    }
	      
	      
	    case 1:{
	      
	      cout << "\n***********************\n\nGive me two points and I'll build a line out of them and find his intercept." << endl;
	      
	      double x1,y1,x2,y2;
	      cout << "Give me the first point (x,y): \nx1 = ";		
	      x1 = SafeCin<double>();
	      cout << "\ny1 = ";	
	      y1 = SafeCin<double>();
	      cout << "\nGive me the second point (x,y):  \nx2 = ";		
	      x2 = SafeCin<double>();
	      cout << "\ny2 = ";
	      y2 = SafeCin<double>();
	      
	      double m, q, x0;
	      
	      //findIntercept() returns default values for each particular case:
	      //-1 returned if parallel to y ax
	      //-2 returned if parallel to x ax
	      
	      switch(findIntercept(x1, y1, x2, y2, m, q, x0))
	      {
		case -1: { cout << "Your line is x = " << x1 << "and its intercept on x ax is " << x1 << endl; break; }
		case -2: { cout << "Your line is y = " << y1 << " and has no intercept on x ax!" << endl;  break; }
		default: cout << "Your line is y = " << m << "x + " << q << " and its intecept on x ax is: " << x0 << endl;
	      }
	      
	      return 0;
	    }
	    
		case 2:{
		  
		  cout << "\n***********************\n\nI'll calculate the lenght of a vector. How many components has your vector?" << endl; 
		  
		  vector < double > v;
		  
		  cout << "N components = ";
		  int ncomp = SafeCin<int>();
		  
		  cout << "\nVery well, give me the components now (x1,x2,x3,...)!" << endl;
		  
		  for(int i = 0; i < ncomp; i++)
		  {
		    cout << "Component " << i+1 << ": " << endl;
		    double curcomp = SafeCin<double>();
		    v.push_back(curcomp);
		  }
		  
		  
		  cout << "\nYour vector is: \n\n(";  
		  
		  for(unsigned int i = 0; i < v.size(); i++)
		  {
		    if(i != (v.size()-1)) 
		      cout << v[i] << ",";
		  }
		  
		  cout << ")\n" << endl;
		  cout << "It's length is " << lenght(v) << endl;
		  
		  return 0;
		}
		
		case 3:{
		  
		  vector < double > E, px, py, pz;	
		  
		  cout << "\n***********************\n\nI'll calculate the invatiant mass of N particles." << endl;
		  cout << "How many particles do you want? N = ";
		  int N = SafeCin<int>();
		  
		  
		  for(int i = 0; i < N; i++)
		  {	
		    cout << "\nGive me the 4-vector of particle " << i+1 << ":\nE = ";			
		    double val = SafeCin<double>();
		    if(val < 0) { cout << "Energy cannot be negative, retry." << endl; i--; continue; }
		    E.push_back(val);
		    
		    cout << "\npx = ";			
		    val = SafeCin<double>();
		    px.push_back(val);
		    
		    cout << "\npy = ";			
		    val = SafeCin<double>();
		    py.push_back(val);
		    
		    cout << "\npz = ";			
		    val = SafeCin<double>();
		    pz.push_back(val);
		  }
		  
		  
		  double mm = invMass(E,px,py,pz);
		  
		  if(mm < 0) 
		    cout << "Etot is less then |ptot|, this is not physical!!!" << endl;
		  else 
		    cout << "The invariant mass of your particles is: " << mm << endl;
		  
		  return 0;
		}
		
		case 4:	{
		  
		  double a = 0, b = 0, c = 0;
		  
		  cout << "\n***********************\n\nThe equation to solve is ax^2 + bx + c = 0. Enter a, b and c" << endl;
		  cout << "\na = ";	
		  a = SafeCin<double>();
		  cout << "\nb = ";	
		  b = SafeCin<double>();
		  cout << "\nc = ";	
		  c = SafeCin<double>();
		  
		  double res1, res2;
		  
		  if( extractRoots(a,b,c,res1,res2) ) 
		    cout << "\nRoot are imaginary... sorry." << endl;
		  else	
		    cout << "\nThe two roots are: " << res1 << " and " << res2 << endl;
		  
		  return 0;
		}
		
		default: return 1;
	    }
}





int performMaths()
{
  cout << "\nHi! You again, choosing deeper and deeper. Is seems you like maths so here is what you can do:" << endl;
  cout << "'1' additions" << endl;
  cout << "'2' subtractions" << endl;
  cout << "'3' multiplications" << endl;
  cout << "'4' dicisions" << endl;
  cout << "\n>> ";
  
  int choice = SafeCin<int>();
  
  
  if(choice < 0 || choice > 4) { cout << "Choice non available, you'll have to start again." << endl; return 1; }
  else
  {
	cout << "\n***********************\n\n Ok, enter two numbers now a and b and I'll perform the operation you requested" << endl;
	cout << "\na = ";	
	double a = SafeCin<double>();
	cout << "\nb = ";	
	double b = SafeCin<double>();
  
	switch(choice)
	{
	  case 1: {
	  
	    double res = add(a,b);
	    
	    cout << "\na + b = " << res << endl;
	   
	    return 0;
	  }
	  
	  
	  case 2: {
	    
	    double res = subtract(a,b);
	    
	    cout << "\na - b = " << res << endl;
	    
	    return 0;
	  }
	  
	  
	  case 3: {
	    
	    double res = multiply(a,b);
	    
	    cout << "\na * b = " << res << endl;
	    
	    return 0;
	  }
	  
	  
	  
	  case 4: {
	    
	    double res = divide(a,b);
	    
	    cout << "\na / b = " << res << endl;
	    
	    return 0;
	  }
    
	  default: return 1;
    
	}
  } 
}



