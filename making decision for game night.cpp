//Work done by Anson Mou and Vansh Shah

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "enter hungry (0) or not hungry (1), day of the week" 
	<< ", time in pm hour: ";
	int hungry = 0;
	string day = "";
	int time = 0;
	cin >> hungry >> day >> time;
	
	string food = "";
	string game = "";
	if (hungry == 0)
	{
		food = "order pizza";
	}
	else
	{
		food = "serve chips";
	}
	
	if (day == "weekday")
	{
		if (time < 7 || time < 9)
			game = "catan";
		else 
			game = "codenames";
	}
	if (day == "friday" || day == "saturday")
	{
		if (time < 7)
			game = "spirit island";
		else if (time < 9)
			game = "ticket to ride";
		else
			game = "codenames";
	}
	else
	{
		if (time < 7 || time < 9)
			game = "mysterium";
		else if (time > 9)
			game = "codenames";
	}
	
	if (hungry == 0)
		cout << "Since hungry" << " " << food << ", on " << day << " " << time << 
		" play " << game;
	else
		cout << "Since not hungry" << " " << food << ", on " << day << " " << time 
		<< " play " << game;
	
	return EXIT_SUCCESS;
}

/*
enter hungry (0) or not hungry (1), day of the week, time in pm hour: 0 saturday 8
Since hungry order pizza, on saturday 8 play ticket to ride
--------------------------------
Process exited after 6.711 seconds with return value 0
Press any key to continue . . .

enter hungry (0) or not hungry (1), day of the week, time in pm hour: 1 weekday 10
Since not hungry serve chips, on weekday 10 play codenames
--------------------------------
Process exited after 24.12 seconds with return value 0
Press any key to continue . . .

enter hungry (0) or not hungry (1), day of the week, time in pm hour: 0 sunday 4
Since hungry order pizza, on sunday 4 play mysterium
--------------------------------
Process exited after 5.913 seconds with return value 0
Press any key to continue . . .
*/