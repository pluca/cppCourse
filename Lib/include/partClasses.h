#ifndef PARTCLASSES_H
#define PARTCLASSES_H

#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include "physClasses.h"


using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;
using std::sqrt;
using std::pow;




//Implements an intelligent container for particle properties 

class ParticleInfo
{
  typedef std::map < string, int > PartNameID;
  typedef std::map < int, string > PartIDName;
  typedef std::map < int, int > PartIDCh;
  typedef std::map < int, double > PartIDMass;
  
  PartNameID names_;
  PartIDName ids_;
  PartIDCh charges_;
  PartIDMass masses_;
  
public:
  
  ////////////////////////////////////////////////////// Constructors
  
  ParticleInfo(){};
  
  ParticleInfo( string name, int id, int ch, double mass )
  {
    names_[name] = id;
    ids_[id] = name;
    charges_[id] = ch;
    masses_[id] = mass;
  }
  
  ParticleInfo( const ParticleInfo &p ) :
  names_(p.names_), ids_(p.ids_), charges_(p.charges_), masses_(p.masses_) 
  {}
  
  //////////////////////////////////////////////////////// Methods
  
  unsigned int size() { return ids_.size(); } 
  
  int getPDGcode(string name)
  {
    PartNameID::iterator p = names_.find(name);
    
    if( p != names_.end() ) return (*p).second;
    else return 0;
  }
  
  string getName(int pdg)
  {
    PartIDName::iterator p = ids_.find(pdg);
    
    if( p != ids_.end() ) return (*p).second;
    else return 0;
  }
  
  double getMassMeV(int id)
  {
    PartIDMass::iterator p = masses_.find(id);
    
    if( p != masses_.end() ) return (*p).second;
    else return 0;
  }
  
  double getMassMeV(string name)
  {
    int pdg = getPDGcode(name);
    
    PartIDMass::iterator p = masses_.find(pdg);
    
    if( p != masses_.end() ) return (*p).second;
    else return 0;
  }
  
  double getMassGeV(int id) { return this->getMassMeV(id)/1000; }
  
  double getMassGeV(string name) { return this->getMassMeV(name)/1000; }
  
  int getCh(int id)
  {
    PartIDCh::iterator p = charges_.find(id);
    
    if( p != charges_.end() ) return (*p).second;
    else return 0;
  }
  
  int getCh(string name)
  {
    int pdg = getPDGcode(name);
    
    PartIDCh::iterator p = charges_.find(pdg);
    
    if( p != charges_.end() ) return (*p).second;
    else return 0;
  }
  
  int insert( string name, int id, int ch, double mass )
  {
    PartNameID::iterator p = names_.find(name);
    PartIDName::iterator q = ids_.find(id);
    
    if( p == names_.end() && q == ids_.end() )
    {
      names_[name] = id;
      ids_[id] = name;
      charges_[id] = ch;
      masses_[id] = mass;
      
      return 1;
    }
    else
      return 0;
  }
  
  
  ParticleInfo getParticleInfo( int id )
  {
    string name = getName(id);
    int ch = getCh(id);
    double mass = getMassMeV(id);
    
    ParticleInfo res(name,id,ch,mass);
    
    return res;
  }
  
  ////////////////////////////////////////////////////// Operators
  
  ParticleInfo& operator=( const ParticleInfo &p )
  {
    if( &p != this )
    {
      masses_ = p.masses_;
      charges_ = p.charges_;
      ids_ = p.ids_;
      names_ = p.names_;
    }
    
    return *this;
  }
  
};















//Implements a Particle class where each object contains physical and kinematical informations
//Furthermore the class automatically relates some particle names to their mass.


class Particle
{
  string name_;
  FourVector v4_;
  double m_;
  int ch_;
  bool isValid_;
  ParticleInfo pinfo_;
  
  void setMassFromName(string name);
  
  bool massCheck() { 
    if( std::abs(m_ - v4_.getT()) < 1e-14 )
      return true;
    else
      return false;
  }
  
  double calcEnergy() { return sqrt( pow(m_,2) + pow(v4_.getP(),2) ); };
  
public:
  
  ////////////////////////////////// Constructors
  
  Particle(){ isValid_ = false; };
  
  Particle( string name, double px, double py, double pz ) :
  name_(name), isValid_(true)
  {
    v4_.setXYZ(px,py,pz);
    setMassFromName(name);
  };
  
  
  Particle( string name, double px, double py, double pz, double m, int ch ) :
  name_(name), m_(m), ch_(ch), isValid_(true)
  {
    v4_.setTXYZ( this->calcEnergy(), px, py, pz );
    if( !massCheck() ) isValid_ = false;
    
  };
  
  Particle( string name, ThreeVector v3 ) :
  name_(name), isValid_(true)
  {
    v4_.set3Vector(v3);
    setMassFromName(name);
  };
  
  Particle( string name, FourVector v4 ) :
  name_(name), v4_(v4), isValid_(true)
  {    
    setMassFromName(name);
    if( !massCheck() ) isValid_ = false;
  };
  
  Particle( const Particle &p ) :
  name_(p.name_), v4_(p.v4_), m_(p.m_), ch_(p.ch_), isValid_(p.isValid_)
  {};

  Particle( const ParticleInfo &pinfo ) :
  pinfo_(pinfo)
  {};
  
  ~Particle() {};
  
  
  /////////////////////////////////////////// IO
  
  void coutProperties();
  
  //////////////////////////////////////////// Public methods
  
  string getName() { return name_; };
  
  double getPx() { return v4_.getX(); };
  
  double getPy() { return v4_.getY(); };
  
  double getPz() { return v4_.getZ(); };
  
  ThreeVector get3Vector() { return v4_.get3Vector(); };
  
  double getP() { return v4_.get3Vector().getP(); };
  
  int getCharge() { 
    if(isValid_) cout << "Charge could not be right" << endl;  
    return ch_; 
  };
  
  double getMassGeV() { 
    if(isValid_) cout << "Mass could not be right" << endl;
    return m_; 
  };
  
  double getEnergy() { 
    if(isValid_) cout << "Energy could not be right" << endl;
    return v4_.getT(); 
  };
  
  FourVector get4Vector() { return v4_; };
  
  bool isValid() { return isValid_; };
  
  void setName( string name ) { name_ = name; };
  
  void setPx( double px ) { v4_.setX(px); };
  
  void setPy( double py ) { v4_.setY(py); };
  
  void setPz( double pz ) { v4_.setZ(pz); };
  
  void setP( double px, double py, double pz ) { v4_.setXYZ(px, py, pz); };
  
  void setM( double m ) { m_ = m; if( massCheck() ) isValid_ = false; };
  
  void set4Vector( FourVector v4 ) { v4_ = v4; if( massCheck() ) isValid_ = false; };
  
  void setCh( int ch ) { ch_ = ch; };
  
  void setPartInfo( ParticleInfo& pinfo ) { pinfo_ = pinfo; };  
  
  //////////////////////////////////// Operators
  
    
  Particle& operator=( const Particle& p )
  {
    if( &p != this )
    {
      m_ = p.m_;
      ch_ = p.ch_;
      v4_ = p.v4_;
      isValid_ = p.isValid_;
      name_ = p.name_;
    }
    
    return *this;
  }
  
  /*
  bool operator==( const Particle& p )
  {
    if(p.name_ == name_ && p.m_ == m_ && p.v4_ == v4_ && p.ch_ == ch_)
      return true;
    else
      return false;
  }
  
  
  bool operator!=( const Particle& p )
  {
    if( *this == p )
      return false; 
    else 
      return true;
  }
  */
};




#endif