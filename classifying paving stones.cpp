#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	cout << "enter two adjacent sides and a contained angle: ";
	double side1 = 0, side2 = 0, angle = 0;
	cin >> side1 >> side2 >> angle;
	
	const int TOLERANCE_LENGTH = 1;
	const double TOLERANCE_ANGLE = 0.5;
	
	if (angle > 0 && angle < 180 && side1 > 0 && side2 > 0)
		if (abs(angle-90) <= TOLERANCE_ANGLE)
			if (abs(side1-side2) <= TOLERANCE_LENGTH)
				cout << "the paving stone is a square.";
			else
				cout << "the paving stone is a rectangle.";
		else
			cout << "the paving stone is a parallelogram.";
	else
		cout << "invalid data, out of range.";
	
	return EXIT_SUCCESS;
}

/*
enter two adjacent sides and a contained angle: 8.4 6.3 180
invalid data, out of range.
--------------------------------
Process exited after 5.64 seconds with return value 0
Press any key to continue . . .

enter two adjacent sides and a contained angle: 4.1 4.15 90.5
the paving stone is a square.
--------------------------------
Process exited after 6.732 seconds with return value 0
Press any key to continue . . .

enter two adjacent sides and a contained angle: 4 4.16 90.6
the paving stone is a parallelogram.
--------------------------------
Process exited after 8.959 seconds with return value 0
Press any key to continue . . .

enter two adjacent sides and a contained angle: 4.1 18 90.5
the paving stone is a rectangle.
--------------------------------
Process exited after 20.28 seconds with return value 0
Press any key to continue . . .

enter two adjacent sides and a contained angle: 12 6.3 18
the paving stone is a parallelogram.
--------------------------------
Process exited after 10.34 seconds with return value 0
Press any key to continue . . .
*/
