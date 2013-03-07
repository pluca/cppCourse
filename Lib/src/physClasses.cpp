 #include <string>
 #include <cmath>
 #include <iostream>
 #include <stdlib.h>
 #include "pp6io.h"
 #include "physClasses.h"

 
 
 ////////////////////////////// Particle class methods
 
 
 //When name is set also the corresponding mass and change are set if available in the database
 
 void Particle::setMassFromName(string name)
 {
   problems_ = false;
   
   if(name == "mu+") { m_ = 0.1507; ch_ = 1; }
   else if(name == "mu-") { m_ = 0.1507; ch_ = -1; }
   else if(name == "e+") { m_ = 0.00051; ch_ = 1; }
   else if(name == "e-") { m_ = 0.00051; ch_ = -1; }
   else if(name == "pi+") { m_ = 0.1396; ch_ = 1; }
   else if(name == "pi-") { m_ = 0.1396; ch_ = -1; }
   else if(name == "K+") { m_ = 0.4937; ch_ = 1; }
   else if(name == "K-") { m_ = 0.4937; ch_ = -1; }
   else if(name == "p+") { m_ = 0.9383; ch_ = 1; }
   else if(name == "p-") { m_ = 0.9383; ch_ = -1; }
   else { m_ = -1; ch_ = 0; problems_ = true; }
 }
 
 
 
 //Prints particle properties
 
 void Particle::coutProperties()
 {
   cout << "\n----------------\n\n";
   if(problems_) cout << "Some properties have not been filled correctly and may be wrong" << endl;
	   cout << "Name = " << name_ << endl;
   cout << "p = (" << px_ << ", " << py_ << ", "<< pz_ << ")" << endl;  
   cout << "mass = " << m_ << endl;  
   cout << "charge = " << ch_ << endl;  
   cout << "\n-----------------" << endl;
 }
 
 
 
 
 
 ////////////////////////////// FourVector class methods
 
 
 // Generates a random FourVector
 
 FourVector::FourVector(int seed)
 {
   srand (seed);   
   t_ = rand()%100000;
   
   srand (seed+1); 
   x_ = rand()%200000 - 100000;
   
   srand (seed+2); 
   y_ = rand()%200000 - 100000;
   
   srand (seed+3); 
   z_ = rand()%200000 - 100000;
 }
 
 
 // Boosts a FourVector with a velocity v along z
 
 void FourVector::boost_z( double v )
 {
   // N.B.: v must be in c = 1 units
   double gamma = sqrt(1 - pow(v,2));
   double beta = v;
   
   t_ = gamma * (t_ - beta*z_);
   x_ = x_;
   y_ = y_;
   z_ = gamma * (z_ - beta*t_);
   
 }
 


 
 