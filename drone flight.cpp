//Work done by Anson Mou and Myles-Cohen Chan

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream fin("drone.txt");
	if (!fin)
	{
		cout << "File not found" << endl;
		return EXIT_FAILURE;
	}
	
	const int X = 0, Y = 0, Z = 40, SPEED = 5;
	double x = 0, y = 0, z = 0, distance = 0, time = 0;
	int minWait = 0;
	
	while (fin >> x >> y >> z >> minWait)
	{
		double x2 = X-x, y2 = Y-y, z2 = Z-z;
		distance = (sqrt(pow(x2, 2)+pow(y2, 2)+pow(z2,2)))*2;
		time = distance/(SPEED*60);
		if (distance == 0)
		{
			cout << "No message" << endl;
		}
		else
		{
			cout << distance << " m travelled, " << "waiting " 
			<< (minWait/(minWait+time))*100 << "%" << endl;
		}
	}
	
	fin.close();
	return EXIT_SUCCESS;
}

/*
451.612 m travelled, waiting 0%
793.825 m travelled, waiting 53.1342%
No message
224.754 m travelled, waiting 92.3154%
451.313 m travelled, waiting 82.3106%
450.757 m travelled, waiting 57.1017%
528.986 m travelled, waiting 53.145%
377.625 m travelled, waiting 84.7586%
484.785 m travelled, waiting 86.0885%
563.037 m travelled, waiting 34.761%
322.709 m travelled, waiting 86.6798%
353.464 m travelled, waiting 77.2467%
284.055 m travelled, waiting 67.8691%
779.791 m travelled, waiting 0%
437.61 m travelled, waiting 73.2775%
572.077 m travelled, waiting 80.7516%
689.875 m travelled, waiting 63.4963%
474.03 m travelled, waiting 55.8643%
213.734 m travelled, waiting 0%
583.527 m travelled, waiting 33.9548%
534.642 m travelled, waiting 77.0996%
463.579 m travelled, waiting 0%
424.702 m travelled, waiting 77.9341%
452.132 m travelled, waiting 82.2842%
395.063 m travelled, waiting 0%
594.519 m travelled, waiting 81.9543%
373.795 m travelled, waiting 86.5241%
448.015 m travelled, waiting 66.7648%
622.92 m travelled, waiting 49.0629%
548.604 m travelled, waiting 0%
532.825 m travelled, waiting 36.022%
576.064 m travelled, waiting 75.7555%
435.999 m travelled, waiting 86.097%
406.978 m travelled, waiting 59.5842%
378.972 m travelled, waiting 84.7125%
675.323 m travelled, waiting 0%
256.914 m travelled, waiting 0%
535.79 m travelled, waiting 0%
308.448 m travelled, waiting 88.6116%
527.312 m travelled, waiting 53.224%
252.073 m travelled, waiting 54.3407%
575.899 m travelled, waiting 78.4783%
No message
371.864 m travelled, waiting 80.134%
478.049 m travelled, waiting 38.558%
519.869 m travelled, waiting 63.3861%
663.335 m travelled, waiting 69.3374%
569.167 m travelled, waiting 0%
461.682 m travelled, waiting 81.9774%
96.317 m travelled, waiting 0%
392.676 m travelled, waiting 88.4258%
114.899 m travelled, waiting 93.9997%
436.964 m travelled, waiting 0%
213.913 m travelled, waiting 92.6589%
195.835 m travelled, waiting 82.1292%
146.464 m travelled, waiting 89.1223%
586.344 m travelled, waiting 82.1582%
563.491 m travelled, waiting 61.4968%
726.986 m travelled, waiting 0%
497.671 m travelled, waiting 84.4365%
662.553 m travelled, waiting 0%
240.297 m travelled, waiting 91.8275%
293.537 m travelled, waiting 89.1022%
632.864 m travelled, waiting 0%
177.181 m travelled, waiting 91.0387%
497.643 m travelled, waiting 54.6626%
562.683 m travelled, waiting 0%
466.442 m travelled, waiting 0%
696.334 m travelled, waiting 81.1615%
521.419 m travelled, waiting 53.5036%
448.681 m travelled, waiting 84.2495%
296.343 m travelled, waiting 50.3066%
431.077 m travelled, waiting 86.2323%
490.678 m travelled, waiting 78.5794%
377.437 m travelled, waiting 76.0728%
471.488 m travelled, waiting 76.0847%
289.643 m travelled, waiting 0%
0.72111 m travelled, waiting 0%
425.227 m travelled, waiting 0%
641.27 m travelled, waiting 78.9144%
569.467 m travelled, waiting 34.5039%
519.235 m travelled, waiting 0%
449.804 m travelled, waiting 85.7196%
667.371 m travelled, waiting 75.8843%
317.702 m travelled, waiting 86.8593%

--------------------------------
Process exited after 0.4574 seconds with return value 0
Press any key to continue . . .
*/