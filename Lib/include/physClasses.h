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
using std::sqrt;
using std::pow;


//This class implements a normal three vector


class ThreeVector
{
  double x_, y_, z_;
  
public:
  
  ///////////////////////////////////////////// Constructors
  
  ThreeVector() {};
  
  ThreeVector( int seed );
  
  ThreeVector( const double x, const double y, const double z ) :
  x_(x), y_(y), z_(z)
  {};
  
  ThreeVector(const ThreeVector &v) :
  x_(v.x_), y_(v.y_), z_(v.z_)
  {};
  
  ~ThreeVector() { //cout << "Deleting a ThreeVector object" << endl; 
  };
  
  
  
  ///////////////////////////////////////////  IO
  
  
  void coutComp() { cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";  };
  
  
  //////////////////////////////////////// Methods
  
  double getX() { return x_; };
  
  double getY() { return y_; };
  
  double getZ() { return z_; };
  
  double * getComp() { double *res = new double[3]; res[0] = x_; res[1] = y_; res[2] = z_; return res; };
  
  void setX( double x ) { x_ = x; };
  
  void setY( double y ) { y_ = y; };
  
  void setZ( double z ) { z_ = z; };
  
  void setXYZ( double x, double y, double z ) { x_ = x; y_ = y; z_ = z; };
  
  double getP() { return sqrt( pow(x_,2) + pow(y_,2) + pow(z_,2) ); }
  
  
  
  ///////////////////////////////////////// Operators
  
  ThreeVector& operator=( const ThreeVector& v )
  {
    if( &v != this )
    {
      x_ = v.x_;
      y_ = v.y_;
      z_ = v.z_;
    }
    
    return *this;
  }
  
  ThreeVector& operator+=( const ThreeVector& v )
  {
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    
    return *this;
  }
  
  ThreeVector& operator-=( const ThreeVector& v )
  {
    x_ -= v.x_;
    y_ -= v.y_;
    z_ -= v.z_;
    
    return *this;
  }
  
  ThreeVector operator+( const ThreeVector& v )
  {
    ThreeVector res(x_ + v.x_, y_ + v.y_, z_ + v.z_ );
    return res;
  }
  
  
  ThreeVector operator-( const ThreeVector& v )
  {
    ThreeVector res(x_ - v.x_, y_ - v.y_, z_ - v.z_ );
    return res;
  }
  
  bool operator==( const ThreeVector& v )
  {
    if(v.x_ == x_ && v.y_ == y_ && v.z_ == z_ )
      return true;
    else
      return false;
  }
  
  
  bool operator!=( const ThreeVector& v )
  {
    if( *this == v )
      return false; 
    else 
      return true;
  }
  
  
};
   




//Implements a Lotentz four vector class


class FourVector
{
  double t_;
  ThreeVector v3_;
  
public:
  
  ///////////////////////////////////////////// Constructors
  
  FourVector() {};
  
  FourVector( int seed );
  
  FourVector( const double t, const double x, const double y, const double z ) :
  t_(t)
  {
    v3_.setXYZ(x,y,z);
  };
  
  FourVector( const double t, const ThreeVector v ) :
  t_(t), v3_(v)
  {};
  
  FourVector(const FourVector &v) :
  t_(v.t_), v3_(v.v3_)
  {};
  
  ~FourVector() {};
  
  
  
  ///////////////////////////////////////////  IO
  
  
  void coutComp() { cout << "(" << t_ << ", " << v3_.getX() << ", " << v3_.getY() << ", " << v3_.getZ() << ")";  };
  
  
  //////////////////////////////////////// Methods
  
  double getT() { return t_; };
  
  double getX() { return v3_.getX(); };
  
  double getY() { return v3_.getY(); };
  
  double getZ() { return v3_.getZ(); };
  
  double * getComp() { double *res = new double[4]; res[0] = t_; res[1] = v3_.getX(); res[2] = v3_.getY(); res[3] = v3_.getZ(); return res; };
  
  ThreeVector get3Vector() { return v3_; };
  
  void setT( double t ) { t_ = t; };
  
  void setX( double x ) { v3_.setX(x); };
  
  void setY( double y ) { v3_.setY(y); };
  
  void setZ( double z ) { v3_.setZ(z); };
  
  void set3Vector( ThreeVector v ) { v3_ = v; };
  
  void setXYZ( double x, double y, double z ) { v3_.setXYZ(x,y,z); };
  
  void setTXYZ( double t, double x, double y, double z ) { t_ = t; v3_.setXYZ(x,y,z); };
  
  double interval() { return sqrt ( pow(t_,2) - pow(v3_.getP(),2) ); }
  
  double getP() { return v3_.getP(); }
  
  void boost_z( double v );
  
  
  
  ///////////////////////////////////////// Operators
  
  FourVector& operator=( const FourVector& v )
  {
    if( &v != this )
    {
      t_ = v.t_;
      v3_ = v.v3_;
    }
    
    return *this;
  }
  
  FourVector& operator+=( const FourVector& v )
  {
    t_ += v.t_;
    v3_ += v.v3_ ;
    
    return *this;
  }
  
  FourVector& operator-=( const FourVector& v )
  {
    t_ -= v.t_;
    v3_ -= v.v3_ ;
    
    return *this;
  }
  
  FourVector operator+( const FourVector& v )
  {
    FourVector res(t_ + v.t_, v3_ + v.v3_ );
    return res;
  }
  
  
  FourVector operator-( const FourVector& v )
  {
    FourVector res(t_ - v.t_, v3_ - v.v3_);
    return res;
  }
  
  
  bool operator==( const FourVector& v )
  {
    if( v.t_ == t_ && v3_ == v.v3_ )
      return true;
    else
      return false;
  }
  
  
  bool operator!=( const FourVector& v )
  {
    if( *this == v )
      return false; 
    else 
      return true;
  }
  
  
};




#endif