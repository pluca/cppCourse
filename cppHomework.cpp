#include <cmath>
#include <vector>
#include <iostream>
#include <climits>

#include "day1Operations.h"
#include "day2Operations.h"
#include "day3Operations.h"
#include "day4Operations.h"
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
		cout << "'...' I'm sure you understood how it works. Days are available from 1 up to 3. " << endl;
		cout << "\n>> ";
		
		int choice = SafeCin<int>();
		
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
		  
		  case 3:{
		    
		    day3Interface();
		    
		    break;
		  }

		  case 4:{
		    
		    day4Interface();
		    
		    break;
		  }
		  
		  default: cout << "\nChoice not allowed, retry!" << endl;
		  
		}

		cout << "\n*******************************\n\nType any charachter to restart or 'q' to quit.\n" << endl;
		cin >> quit;	
	
	} while(quit!='q');
	
	return 0;

}



