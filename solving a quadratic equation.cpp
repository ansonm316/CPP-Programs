#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	cout << "enter values of a, b, c: ";
	double a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	
	if (a != 0)
	{
		double discriminant = 0;
		discriminant = 	b*b-4*a*c;
		double x1 = 0, x2 = 0;
		x1 = (-b+sqrt(discriminant))/(2*a);
		x2 = (-b-sqrt(discriminant))/(2*a);
		
		cout << "roots of the quadratic equation are: " << x1 << ", " << x2;
	}
	else
	{
		cout << "a must not equal to 0.";
	}
	
	return EXIT_SUCCESS;
}

/*
enter values of a, b, c: 3 -6 3
roots of the quadratic equation are: 1, 1
--------------------------------
Process exited after 1.985 seconds with return value 0
Press any key to continue . . .
*/