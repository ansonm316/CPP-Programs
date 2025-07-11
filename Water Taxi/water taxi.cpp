//Work done by Anson Mou & Liam Bruins

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

double calcDistance(double x1, double x2, double y1, double y2)
{
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main()
{
	ofstream fout("report.txt");
	ifstream fin("taxi.txt");
	if (!fin)
	{
		cout << "No file" << endl;
		return EXIT_FAILURE;
	}
	
	const double COST_PER_KM = 2.85, COST_PER_STOP = 18.5;
	int oversize = 0, numStop = 0, tripNum = 0;
	double totalDist = 0, totalCost = 0, maxDist = 0, minCost = 1000;
	
	while (fin >> oversize)
	{
		double x1 = 0, x2 = 0, y1 = 0, y2 = 0, legDist = 0, tripDist = 0, 
		tripCost = 0;
		fin >> numStop;
		for (int count = 1; count <= numStop; count++)
		{
			fin >> x1 >> y1;
			legDist = calcDistance(x1, x2, y1, y2);
			tripDist += legDist;
			x2 = x1;
			y2 = y1;
		}
		
		tripDist = tripDist + sqrt(pow(x2, 2)+pow(y2, 2));
		if (tripDist > maxDist)
			maxDist = tripDist;
		totalDist += tripDist;
		
		tripCost = tripDist*COST_PER_KM + COST_PER_STOP*numStop;
		tripCost = tripCost + 0.2*tripCost*oversize;
		if (tripCost < minCost)
			minCost = tripCost;
		totalCost += tripCost;
		
		tripNum++;
		 
		if (tripNum <= 6 || tripNum%10 == 6)
		{
			fout << fixed << setprecision(2);
			
			fout << "trip#" << setw(6) << "stops" << setw(5) << "over" << setw(9) <<
		 	"tripDist" << setw(9) << "tripCost" << setw(10) << "totalDist" << 
			 setw(10) << "totalCost" << endl;
		 
		 	fout << setw(5) << tripNum << setw(6) << numStop << setw(5) << oversize 
			<< setw(9) << tripDist << setw(9) << tripCost << setw(10) << totalDist << 
			setw(10) << totalCost << endl;
		}
	}
	
	fout << "total distance travelled for the month: " << totalDist << endl;
	fout << "total amount collected from all customers for the month: "
	<< totalCost << endl;
	fout << "length of longest trip: " << maxDist << endl;
	fout << "cost of least expensive trip: " << minCost << endl;

	fin.close();
	return EXIT_SUCCESS;
}

/*
trip# stops over tripDist tripCost totalDist totalCost
    1     1    0    20.40    76.64     20.40     76.64
trip# stops over tripDist tripCost totalDist totalCost
    2     2    1    13.07    89.09     33.47    165.73
trip# stops over tripDist tripCost totalDist totalCost
    3     4    1    40.72   228.05     74.18    393.78
trip# stops over tripDist tripCost totalDist totalCost
    4     3    1    44.20   217.78    118.39    611.55
trip# stops over tripDist tripCost totalDist totalCost
    5     1    1    11.03    59.93    129.42    671.48
trip# stops over tripDist tripCost totalDist totalCost
    6     2    0    21.65    98.70    151.07    770.18
trip# stops over tripDist tripCost totalDist totalCost
   16     2    0    38.55   146.88    586.92   2543.35
trip# stops over tripDist tripCost totalDist totalCost
   26     3    0    52.02   203.76   1025.51   4340.67
trip# stops over tripDist tripCost totalDist totalCost
   36     3    1    44.43   218.56   1421.14   6032.28
trip# stops over tripDist tripCost totalDist totalCost
   46     1    1    23.05   101.03   1768.19   7603.15
trip# stops over tripDist tripCost totalDist totalCost
   56     3    0    73.87   266.03   2241.21   9465.03
trip# stops over tripDist tripCost totalDist totalCost
   66     3    0    59.90   226.23   2723.44  11456.32
trip# stops over tripDist tripCost totalDist totalCost
   76     1    1    27.68   116.86   3157.72  13193.79
trip# stops over tripDist tripCost totalDist totalCost
   86     1    0    27.46    96.77   3577.86  14850.97
trip# stops over tripDist tripCost totalDist totalCost
   96     3    0    39.43   167.88   3964.90  16480.56
trip# stops over tripDist tripCost totalDist totalCost
  106     3    0    49.34   196.12   4297.56  17902.59
trip# stops over tripDist tripCost totalDist totalCost
  116     3    0    76.20   272.67   4719.05  19589.59
trip# stops over tripDist tripCost totalDist totalCost
  126     3    0    49.24   195.83   5116.50  21267.42
trip# stops over tripDist tripCost totalDist totalCost
  136     1    0    29.26   101.89   5452.83  22619.92
trip# stops over tripDist tripCost totalDist totalCost
  146     3    1    55.88   257.71   5832.74  24178.35
trip# stops over tripDist tripCost totalDist totalCost
  156     1    0    24.63    88.70   6295.13  26075.60
trip# stops over tripDist tripCost totalDist totalCost
  166     3    0    45.26   184.48   6830.14  28378.37
trip# stops over tripDist tripCost totalDist totalCost
  176     2    1    47.54   206.97   7336.67  30482.27
trip# stops over tripDist tripCost totalDist totalCost
  186     2    1    62.09   256.75   7805.48  32528.72
trip# stops over tripDist tripCost totalDist totalCost
  196     3    1    61.32   276.32   8399.18  34908.53
trip# stops over tripDist tripCost totalDist totalCost
  206     1    1    16.19    77.57   8826.53  36757.36
trip# stops over tripDist tripCost totalDist totalCost
  216     2    1    28.74   142.69   9198.79  38275.93
trip# stops over tripDist tripCost totalDist totalCost
  226     1    0    26.25    93.31   9528.62  39677.10
total distance travelled for the month: 9599.28
total amount collected from all customers for the month: 39985.34
length of longest trip: 140.40
cost of least expensive trip: 35.50
*/