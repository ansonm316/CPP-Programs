#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	cout << "enter x & y coordinates: ";
	double x = 0; double y = 0;
	cin >> x >> y;
	
	double radius = 0;
	radius = sqrt(x*x + y*y);
	double radians = 0;
	radians = atan(y/x);
	double degrees = 0;
	degrees = radians * 180/M_PI;
	
	cout << "radius: " << radius << endl;
	cout << "theta (radians): " << radians << endl;
	cout << "theta (degrees): " << degrees;
	
	return EXIT_SUCCESS;
}

/*
enter x & y coordinates: 0.8 -9.0
radius: 9.03549
theta (radians): -1.48214
theta (degrees): -84.9204
--------------------------------
Process exited after 4.944 seconds with return value 0
Press any key to continue . . .
*/