#ifndef PP6_MATH_HH
#define PP6_MATH_HH 

#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;

//Definition of Maths functions for pp6 course


void swap(double &a, double &b);

int extractRoots(double a, double b, double c, double &r1, double &r2);

double invMass(vector<double> E, vector<double> px, vector<double> py, vector<double> pz);

double twoPartInvMass(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2);

int findIntercept(double x1, double y1, double x2, double y2, double &m, double &q, double &x0);

double lenght(vector<double> v);

vector <double> sort(vector <double> v, bool decreasing = true);

//int sortAndKeepTrack(vector <double> v, vector <int> &indices, bool decreasing)

double add(double a, double b);

double multiply(double a, double b);

double subtract(double a, double b);

double divide(double a, double b);

double average(vector <double> v);

double sigma(vector <double> v);

double max(vector <double> v);

double findMax(vector <double> v);

int RandomNumber();


#endif
