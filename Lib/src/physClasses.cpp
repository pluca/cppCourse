 #include <string>
 #include <cmath>
 #include <iostream>
 #include <cstdlib>
 #include "pp6io.h"
 #include "physClasses.h"

 
  
 ////////////////////////////// FourVector class methods
 
 
 // Generates a random FourVector
 
 FourVector::FourVector(int seed)
 {
   std::srand (seed);   
   
   t_ = rand()%100000;
   double x = rand()%200000 - 100000;
   double y = rand()%200000 - 100000;
   double z = rand()%200000 - 100000;
   
   v3_.setXYZ(x,y,z);
 }
 
 
 // Boosts a FourVector with a velocity v along z
 
 void FourVector::boost_z( double v )
 {
   // N.B.: v must be in c = 1 units
   double gamma = sqrt(1 - pow(v,2));
   double beta = v;
   
   double oldz = v3_.getZ();
   
   t_ = gamma * (t_ - beta*oldz);
   double x = v3_.getX();
   double y = v3_.getY();
   double z = gamma * (oldz - beta*t_);
   
   v3_.setXYZ(x,y,z);
 }
 


 
 