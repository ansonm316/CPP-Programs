/*
Anson Mou
Checked output with Jason Nguyen
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ofstream fileOut("square.txt");
    
    int number = 0;
    
    cout << "Enter a number: ";
    cin >> number;

    cout << "The square of " << number 
         << " is " << number*number << endl;

    cout << "& the cube of " << number
         << " is " << number*number*number << endl;
         
    fileOut << number << " squared is " << number*number << endl;

	return EXIT_SUCCESS;
}

/*

5 squared is 25

Enter a number: 5 
The square of 5 is 25
& the cube of 5 is 125

--------------------------------
Process exited after 1.913 seconds with return value 0
Press any key to continue . . .
*/
