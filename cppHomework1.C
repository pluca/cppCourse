
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

int SafeCinInt()
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

int main()
{
	cout << "\t\t##############################\n\t\t#     PP6 PROGRAM BEGINS     #\n\t\t##############################\n\n";
  
  
	char quit = '0';

	do
	{
		cout << "Nooo, you again...: what do you want do now? Type: " << endl;
		cout << "'1' for finding the intercept" << endl;
		cout << "'2' for calculating lenghts" << endl;
		cout << "'3' for calculating invariant masses" << endl;
		cout << "'4' for solving quadratic equations\n" << endl;

		int choice = SafeCinInt();

		switch(choice)
		{
			case 1:{
				
				cout << "\n***********************\n\nGive me two points and I'll build a line out of them and find his intercept." << endl;

				double x1,y1,x2,y2;
				cout << "Give me the first point (x,y): \nx1 = ";		
				x1 = SafeCinInt();
				cout << "\ny1 = ";	
				y1 = SafeCinInt();
				cout << "\nGive me the second point (x,y):  \nx2 = ";		
				x2 = SafeCinInt();
				cout << "\ny2 = ";
				y2 = SafeCinInt();

				if(abs(x1-x2) > 1e-10)
				{
					double m = (y2-y1)/(x1-x2);
					double q = y1 - m*x1;

					if(abs(m) > 1e-10) 
					{
						cout << "Your line is y = " << m << "x + " << q << ", to find the one on x ax I set y = 0" << endl;
						double x0 = -y1/m;
						cout << "And et voilà, your intecept on x ax is: " << x0 << endl;
					}
					else cout << "Your line is y = " << y1 << " and has no intercept on x ax!" << endl; 
				}
				else cout << "Your line is x = " << x1 << "and its intercept on x ax is " << x1 << endl; 
				

			break;
			}
		
			case 2:{
				cout << "\n***********************\n\nI'll calculate the lenght of a vector. How many components has your vector?" << endl; 
	
				vector < double > v;
				
				cout << "N components = ";
				int ncomp = SafeCinInt();
				
				cout << "\nVery well, give me the components now (x1,x2,x3,...)!" << endl;
				
				for(int i = 0; i < ncomp; i++)
				{
					cout << "Component " << i+1 << ": " << endl;
					double curcomp = SafeCinInt();
					v.push_back(curcomp);
				}


				cout << "\nYour vector is: \n\n(";  

				double length2 = 0;
				for(int i = 0; i < v.size(); i++)
				{ 
					length2 += pow(v[i],2);
					if(i != (v.size()-1)) cout << v[i] << ",";
				}

				cout << ")\n" << endl;
				cout << "It's length is " << sqrt(length2) << endl;

			break;
			}
			
			case 3:{
				
				vector < double > E, px, py, pz;	

				cout << "\n***********************\n\nI'll calculate the invatiant mass of N particles." << endl;
				cout << "How many particles do you want? N = ";
				int N = SafeCinInt();

				
				for(int i = 0; i < N; i++)
				{	
					cout << "\nGive me the 4-vector of particle " << i+1 << ":\nE = ";			
					double val = SafeCinInt();
					if(val < 0) { cout << "Energy cannot be negative, retry." << endl; i--; continue; }
					E.push_back(val);

					cout << "\npx = ";			
					val = SafeCinInt();
					px.push_back(val);

					cout << "\npy = ";			
					val = SafeCinInt();
					py.push_back(val);

					cout << "\npz = ";			
					val = SafeCinInt();
					pz.push_back(val);
				}

				
				double Etot = 0, pxtot = 0, pytot = 0, pztot = 0;

				for(unsigned i = 0; i < E.size(); i++)
				{
					Etot += E[i];
					pxtot += px[i];
					pytot += py[i];
					pztot += pz[i];
				}			

				
				double m2 = Etot*Etot - pxtot*pxtot - pytot*pytot - pztot*pztot;
				if(m2 >=0) cout << "The invariant mass of your particles is: " << sqrt(m2) << endl;
				else cout << "Etot is less then |ptot|, this is not physical!!!" << endl;

			break;
			}
			
			case 4:	{

				double a = 0, b = 0, c = 0;

				cout << "\n***********************\n\nThe equation to solve is ax^2 + bx + c = 0. Enter a, b and c" << endl;
				cout << "\na = ";	
				a = SafeCinInt();
				cout << "\nb = ";	
				b = SafeCinInt();
				cout << "\nc = ";	
				c = SafeCinInt();

				double delta = pow(b,2) - 4*a*c;

				if(delta < 0) cout << "Root are imaginary... sorry." << endl;
				else
				{
					double res1 = -b + sqrt(delta);
					double res2 = -b + sqrt(delta);

					cout << "The two roots are: " << res1 << " and " << res2 << endl;
				}
			}

			break;

			default: cout << "\nChoice not allowed, retry!" << endl;
		}
 

		cout << "\n*******************************\n\nType any charachter to restart or 'q' to quit.\n" << endl;
		cin >> quit;	
	
	} while(quit!='q');

}



