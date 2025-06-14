//Written By Anson Mou & Bianca Cortero

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

double calcTriPerimeter(double sideA, double sideB, double sideC)
{
	return sideA + sideB + sideC;
} //Written by Bianca

double calcTriArea(double sideA, double sideB, double sideC)
{
	double semi = 0;
	semi = calcTriPerimeter(sideA, sideB, sideC)/2;
	return sqrt(semi*(semi-sideA)*(semi-sideB)*(semi-sideC));
} // Written by Anson

double calcQuadPerimeter(double side1, double side2, 
double side3, double side4)
{
	return side1 + side2 + side3 + side4;
} // Written by Bianca

double calcQuadArea(double side1, double side2, double diagonal, 
double side3, double side4)
{
	return calcTriArea(side1, side2, diagonal)+calcTriArea(diagonal, 
	side3, side4);
} // Written by Anson

double calcSectPerimeter(double radius, double angleDegrees)
{
	return (angleDegrees*M_PI*2*radius/360) + 2*radius;
} // Written by Bianca

double calcSectArea(double radius, double angleDegrees)
{
	return angleDegrees*M_PI*pow(radius, 2)/360;
} // Written by Anson

int main()
{
	ifstream fin("jobs.txt");
	
	if (!fin)
	{
		cout << "File not found." << endl;
		return EXIT_FAILURE;
	}
	const double OVERSEED_PER_METERSQUARED = 0.27,
	WEED_PER_METER = 0.85, ADMIN_FEE = 23, TAX = 0.13, 
	WEED_PREVENTION_LIMIT = 150;
	int numJob = 0;
	
	cout << "Job #" << setw(10) << "Seed Area" << setw(10) << "Seed Cost" <<
	setw(13) << "Actual Perim" << setw(10) << "Weed Cost" << setw(10) <<
	"Admin Fee" << setw(7) << "Taxes" << setw(11) << "Total Cost" << endl;
	
	while (fin >> numJob)
	{
		int weedTrim = 0;
		string shape = "";
		double triPerimeter = 0, triArea = 0, quadPerimeter = 0, quadArea = 0,
		sectPerimeter = 0, sectArea = 0, costSeed = 0, costWeed = 0, subtotal = 0,
		totalCost = 0, taxes = 0, adminFee = 0;
		
		fin >> weedTrim >> shape;
		
		if (shape == "tri")
		{
			double sideA = 0, sideB = 0, sideC = 0;
			fin >> sideA >> sideB >> sideC;
			triPerimeter = calcTriPerimeter(sideA, sideB, sideC);
			triArea = calcTriArea(sideA, sideB, sideC);
		
			costSeed = ceil(triArea)*OVERSEED_PER_METERSQUARED;
			costWeed = ceil(triPerimeter)*WEED_PER_METER*weedTrim;
			
			subtotal = costSeed + costWeed;
			
			if (subtotal <= WEED_PREVENTION_LIMIT)
				adminFee = ADMIN_FEE;
			else
				adminFee = 0;
			
			taxes = (subtotal + adminFee) * TAX;
			
			totalCost = subtotal + adminFee + taxes;
			
			cout << fixed << setprecision(2);
			cout << setw(5) << numJob << setw(10) << triArea << setw(10) << costSeed 
			<< setw(13) << triPerimeter << setw(10) << costWeed << setw(10) << 
			adminFee << setw(7) << taxes << setw(11) << totalCost << endl;
		}
		else if (shape == "quad")
		{
			double side1 = 0, side2 = 0, diagonal = 0, side3 = 0, side4 = 0;
			fin >> side1 >> side2 >> diagonal >> side3 >> side4;
			
			quadPerimeter = calcQuadPerimeter(side1, side2, side3, side4);
			quadArea = calcQuadArea(side1, side2, diagonal, side3, side4);
			
			costSeed = ceil(quadArea)*OVERSEED_PER_METERSQUARED;
			costWeed = ceil(quadPerimeter)*WEED_PER_METER*weedTrim;
			
			subtotal = costSeed + costWeed;
			
			if (subtotal <= WEED_PREVENTION_LIMIT)
				adminFee = ADMIN_FEE;
			else
				adminFee = 0;
			
			taxes = (subtotal + adminFee) * TAX;
			totalCost = subtotal + adminFee + taxes;
			
			cout << fixed << setprecision(2);
			cout << setw(5) << numJob << setw(10) << quadArea << setw(10) << costSeed 
			<< setw(13) << quadPerimeter << setw(10) << costWeed << setw(10) << 
			adminFee << setw(7) << taxes << setw(11) << totalCost << endl;
		}
		else
		{
			double radius = 0, angleDegrees = 0;
			fin >> radius >> angleDegrees;
			
			sectPerimeter = calcSectPerimeter(radius, angleDegrees);
			sectArea = calcSectArea(radius, angleDegrees);
			
			costSeed = ceil(sectArea)*OVERSEED_PER_METERSQUARED;
			costWeed = ceil(sectPerimeter)*WEED_PER_METER*weedTrim;
			
			subtotal = costSeed + costWeed;
			
			if (subtotal <= WEED_PREVENTION_LIMIT)
				adminFee = ADMIN_FEE;
			else
				adminFee = 0;
				
			taxes = (subtotal + adminFee) * TAX;
			
			totalCost = subtotal + adminFee + taxes;
			
			cout << fixed << setprecision(2);
			cout << setw(5) << numJob << setw(10) << sectArea << setw(10) << costSeed 
			<< setw(13) << sectPerimeter << setw(10) << costWeed << setw(10) << 
			adminFee << setw(7) << taxes << setw(11) << totalCost << endl;
		}
	}
	
	fin.close();
	return EXIT_SUCCESS;
}

/*
Job # Seed Area Seed Cost Actual Perim Weed Cost Admin Fee  Taxes Total Cost
 7100    600.00    162.00       120.00    102.00      0.00  34.32     298.32
 7101     70.16     19.17        34.40      0.00     23.00   5.48      47.65
 7102      2.36      0.81         7.57      0.00     23.00   3.10      26.91
 7103    784.00    211.68       112.00     95.20      0.00  39.89     346.77
 7104    157.08     42.66        51.42     44.20     23.00  14.28     124.14
 7105      9.00      2.43        12.00      0.00     23.00   3.31      28.74
 7106   2323.24    627.48       192.80    164.05      0.00 102.90     894.43
 7107    197.04     53.46        57.59      0.00     23.00   9.94      86.40
 7108    501.76    135.54        89.60      0.00     23.00  20.61     179.15
 7109     89.92     24.30        38.21     33.15     23.00  10.46      90.91
 7110      8.39      2.43        11.80      0.00     23.00   3.31      28.74
 7111      3.90      1.08         9.00      7.65     23.00   4.12      35.85
 7112     70.56     19.17        33.60     28.90     23.00   9.24      80.31

--------------------------------
Process exited after 0.2821 seconds with return value 0
Press any key to continue . . .
*/