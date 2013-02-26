#ifndef PP6_MATH_HH
#define PP6_MATH_HH 

#include <vector>

using namespace std;

//Definition of Maths functions for pp6 course


void swap(double &a, double &b);

int extractRoots(double a, double b, double c, double &r1, double &r2);

double invMass(vector<double> E, vector<double> px, vector<double> py, vector<double> pz);

int findIntercept(double x1, double y1, double x2, double y2, double &m, double &q, double &x0);

double lenght(vector<double> v);

int sort(double *v, int N, bool decreasing = true);

int sortAndKeepTrack(double *v, int N, int * indices, bool decreasing = true);

double add(double a, double b);

double multiply(double a, double b);

double subtract(double a, double b);

double divide(double a, double b);

double average(double * v, int N);

double sigma(double * v, int N);

double max(double * v, int N);


#endif
