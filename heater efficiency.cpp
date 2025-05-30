#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double mwater = 0, cp = 4.2, deltaT = 0, mgas = 0, hv = 45000;
	
	cout << "Enter the mass of water to be heated in kg: ";
	cin >> mwater;
	
	cout << "Enter the change in temperature in degrees Celsius: ";
	cin >> deltaT;
	
	cout << "Enter the mass of natural gas needed to heat the water in kg: ";
	cin >> mgas;
	
	double energyout = mwater * cp * deltaT;
	double energyin = mgas * hv;
	
	cout << "The efficiency of the water heater is: " << energyout / energyin;
	
	return EXIT_SUCCESS;
}

/*
 Enter the mass of water to be heated in kg: 100
 Enter the change in temperature in degrees Celsius: 60
 Enter the mass of natural gas needed to heat the water in kg: 0.8
 The efficiency of the water heater is: 0.7
 --------------------------------
 Process exited after 16.77 seconds with return value 0
 Press any key to continue . . .
 
 Enter the mass of water to be heated in kg: 10.5
 Enter the change in temperature in degrees Celsius: 21.5
 Enter the mass of natural gas needed to heat the water in kg: 0.05
 The efficiency of the water heater is: 0.4214
 --------------------------------
 Process exited after 8.905 seconds with return value 0
 Press any key to continue . . .
*/
