#ifndef PP6_PHYSCLASSES_HH
#define PP6_PHYSCLASSES_HH

#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;





//Implements a Lotentz four vector class


class FourVector
{
  double t_, x_, y_, z_;
  
public:
  
  ///////////////////////////////////////////// Constructors
  
  FourVector() {};
  
  FourVector( int seed );
  
  FourVector( const double t, const double x, const double y, const double z ) :
  t_(t), x_(x), y_(y), z_(z)
  {};
  
  FourVector(const FourVector &v) :
  t_(v.t_), x_(v.x_), y_(v.y_), z_(v.z_)
  {};
  
  ~FourVector() { //cout << "Deleting a FourVector object" << endl; 
  };
  
  
  
  ///////////////////////////////////////////  IO
  
  
  void coutComp() { cout << "(" << t_ << ", " << x_ << ", " << y_ << ", " << z_ << ")";  };
  
  
  //////////////////////////////////////// Methods
  
  double getT() { return t_; };
  
  double getX() { return x_; };
  
  double getY() { return y_; };
  
  double getZ() { return z_; };
  
  double * getComp() { double *res = new double[4]; res[0] = t_; res[1] = x_; res[2] = y_; res[3] = z_; return res; };
  
  void setT( double t ) { t_ = t; };
  
  void setX( double x ) { x_ = x; };
  
  void setY( double y ) { y_ = y; };
  
  void setZ( double z ) { z_ = z; };
  
  void setZ( double t, double x, double y, double z ) { t_ = t; x_ = x; y_ = y; z_ = z; };
  
  double interval() { return pow(t_,2) - pow(x_,2) - pow(y_,2) - pow(z_,2); }
  
  void boost_z( double v );
  
  
  
  ///////////////////////////////////////// Operators
  
  FourVector& operator=( const FourVector& c )
  {
    //if( &c != &this )
    //{
      t_ = c.t_;
      x_ = c.x_;
      y_ = c.y_;
      z_ = c.z_;
      
      return *this;
    //}
  }
  
  
  FourVector& operator+=( const FourVector& v )
  {
    t_ += v.t_ ;
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    
    return *this;
  }
  
  
  FourVector& operator-=( const FourVector& v )
  {
    t_ -= v.t_ ;
    x_ -= v.x_;
    y_ -= v.y_;
    z_ -= v.z_;
    
    return *this;
  }
  
  
  FourVector operator+( const FourVector& v )
  {
    FourVector res(t_ + v.t_, x_ + v.x_, y_ + v.y_, z_ + v.z_);
    return res;
  }
  
  
  FourVector operator-( const FourVector& v )
  {
    FourVector res(t_ - v.t_, x_ - v.x_, y_ - v.y_, z_ - v.z_);
    return res;
  }
  
  
};




//Implements a Particle class where each object contains physical and kinematical informations
//Furthermore the class automatically relates some particle names to their mass.


class Particle
{
  string name_;
  double px_;
  double py_;
  double pz_;
  double m_;
  int ch_;
  bool problems_;
  
  void setMassFromName(string name);
  
public:
  
  ////////////////////////////////// Constructors
  
  Particle(){ problems_ = true; };
  
  Particle( string name, double px, double py, double pz ) :
  name_(name),
  px_(px),
  py_(py),
  pz_(pz)
  {
    setMassFromName(name);
  };
  
  
  Particle( string name, double px, double py, double pz, double m ) :
  name_(name), px_(px), py_(py), pz_(pz), m_(m)
  {
    if(m_ < 0.) problems_ = true;
    else problems_ = false;    
  };
  
  Particle( string name, double px, double py, double pz, double m, int ch ) :
  name_(name), px_(px), py_(py), pz_(pz), m_(m), ch_(ch)
  {
    if(m_ < 0.) problems_ = true;
    else problems_ = false;
  };
  
  Particle( string name, double px, double py, double pz, int ch ) :
  name_(name), px_(px), py_(py), pz_(pz), ch_(ch)
  {
    setMassFromName(name);	
  };
  
  Particle( const Particle &p ) :
  name_(p.name_), px_(p.px_), py_(p.py_), pz_(p.pz_), m_(p.m_), ch_(p.ch_), problems_(p.problems_)
  {};
  
  ~Particle() { //cout << "Deleting " << name_ << endl;
  };
  
  
  /////////////////////////////////////////// IO
  
  void coutProperties();
  
  //////////////////////////////////////////// Public methods
  
  string getName() { return name_; };
  
  double getPx() { return px_; };
  
  double getPy() { return py_; };
  
  double getPz() { return pz_; };
  
  double * getPComp() { double *res = new double[3]; res[0] = px_; res[1] = py_; res[2] = pz_; return res; };
  
  double getP() { return sqrt( pow(px_,2) + pow(py_,2) + pow(pz_,2) ); };
  
  int getCharge() { if(problems_) cout << "Charge could not be right" << endl;  return ch_; };
  
  double getMass() { if(problems_) cout << "Mass could not be right" << endl; return m_; };
  
  double getEnergy() { 
    if(problems_) cout << "Energy could not be right" << endl;
    return pow(m_,2) + pow( getP(),2 ); 
  };
  
  FourVector get4Vector() { 
    if(problems_) cout << "ATTENTION Energy component could be wrong." << endl; 
    FourVector res(getEnergy(),px_,py_,pz_);
    return res; 
  };
  
  bool problems() { return problems_; };
  
  void setName( string name ) { name_ = name; };
  
  void setPx( double px ) { px_ = px; };
  
  void setPy( double py ) { py_ = py; };
  
  void setPz( double pz ) { pz_ = pz; };
  
  void setP( double px, double py, double pz ) { px_ = px; py_ = py; pz_ = pz; };
  
  void setM( double m ) { m_ = m; };
  
  void setCh( int ch ) { ch_ = ch; };
};





#endif