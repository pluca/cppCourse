#include <iostream>
#include <climits>

#include "pp6io.h"

using namespace std;

int SafeCinNum()
{	
	int number;
	
	do{
		cin >> number;
        	if(cin.fail()) cout << "\aNot a number, retry!" << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');

    	}while(cin.fail());

	return number;
}



double SafeCinDouble()
{	
	double number;
	
	do{
		cin >> number;
        	if(cin.fail()) cout << "\aNot a number, retry!" << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');

    	}while(cin.fail());

	return number;
}