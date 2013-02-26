#include <cmath>
#include <vector>
#include <iostream>
#include <climits>

#include "day1Operations.h"
#include "day2Operations.h"
#include "pp6io.h"

using namespace std;

int main()
{
	cout << "\t\t##############################\n\t\t#     PP6 PROGRAM BEGINS     #\n\t\t##############################\n\n";
  
  
	char quit = '0';

	do
	{
		cout << "Nooo, you again...: what do you want do now? Type: " << endl;
		
		cout << "'1' to perform day 1 operations" << endl;
		cout << "'2' to perform day 2 operations" << endl;
		cout << "'...' I'm sure you understood how it works. Days are available up to 2 included for now. " << endl;
		
		int choice = SafeCinNum();
		
		switch(choice)
		{
		  
		  case 1:{
		    
		    day1Interface();
		    
		    break;
		  }
		  
		  
		  case 2:{
		    
		    day2Interface();
		    
		    break;
		  }
		  
		  default: cout << "\nChoice not allowed, retry!" << endl;
		
		}
 

		cout << "\n*******************************\n\nType any charachter to restart or 'q' to quit.\n" << endl;
		cin >> quit;	
	
	} while(quit!='q');
	
	return 0;

}



