#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	cout << "enter temperature in fahrenheit: ";
	double fahrenheit = 0;
	cin >> fahrenheit;
	
	if (fahrenheit < 135 &&- fahrenheit > -130)
	{
		double celsius = 0;
		celsius = 5*(fahrenheit-32)/9;
		cout << "temperature in celsius: " << celsius;
	}
	else
	{
		cout << "invalid value, must be between -130 and 135";
	}
	
	return EXIT_SUCCESS;
		
}