#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "pp6io.h"
#include "physClasses.h"
#include "partClasses.h" 

////////////////////////////// Particle class methods
 
 
 //When name is set also the corresponding mass and change are set if available in the database
 
 void Particle::setMassFromName(string name)
 {
   isValid_ = true;
   
   /*
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
   */
   
    m_ = pinfo_.getMassGeV(name);
    ch_ = pinfo_.getCh(name);
    
   if( m_ < 0 ){ m_ = -1; ch_ = 0; v4_.setT(-1); isValid_ = false;}
   
   if( isValid_ == true ) v4_.setT( this->calcEnergy() );
 }
 
 
 
 //Prints particle properties
 
 void Particle::coutProperties()
 {
   cout << "\n----------------\n\n";
   if(!isValid_) cout << "Some properties have not been filled correctly and may be wrong" << endl;
   cout << "Name = " << name_ << endl;
   cout << "p = (" << v4_.getT() << ", " << v4_.getX() << ", " << v4_.getY() << ", "<< v4_.getZ() << ")" << endl;  
   cout << "mass = " << m_ << endl;  
   cout << "charge = " << ch_ << endl;  
   cout << "\n-----------------" << endl;
 }
 
 