#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	cout << "enter r1, r2, m: ";
	double r1 = 0, r2 = 0, m = 0;
	cin >> r1 >> r2 >> m;
	
	if (r2 > r1 && r1 > 0 && m > 0)
	{
		double inertia = 0;
		inertia = 2*m*(pow(r2, 5)-pow(r1, 5))/5*(pow(r2, 3)-pow(r1, 3));
		cout << "moment of inertia: " << inertia << " kg*m^2";
		
	}
	else
	{
		cout << "invalid value(s), r2 must be bigger than r1, r1 must be bigger than 0, and mass must be bigger than 0.";
	}
	
	return EXIT_SUCCESS;
}

/*
enter r1, r2, m: 1 2 3
moment of inertia: 260.4 kg*m^2
--------------------------------
Process exited after 3.475 seconds with return value 0
Press any key to continue . . .
*/