#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
	//srand(time(0));

	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	//#define GREEN SetConsoleTextAttribute(h, 10);
	//
	//GREEN; cout << "green" << endl << endl << endl;

	
	/*while (true)
	{
		cout << "\b\b||";
		Sleep(250);
		cout << "\b\b/\\";
		Sleep(250);
		cout << "\b\b--";
		Sleep(250);
		cout << "\b\b\\/";
		Sleep(250);
	}*/

	


	srand(time(NULL));

	const double COEF = 1;
	const int Y_SIZE = 5;
	const int X_SIZE = Y_SIZE * COEF;
	const int RANGE = 9, RANGE_START = 1;

	int arr2D[Y_SIZE][X_SIZE];
	int maxElem, minElem;

	int maxIndexY = 0, maxIndexX = 0, minIndexY = 0, minIndexX = 0;
	int totalSumm = 0, topLeftToBottomRightDiagSumm = 0, bottomLeftToTopRightDiagSumm = 0;

	for (int y = 0; y < Y_SIZE; y++)
	{
		for (int x = 0; x < X_SIZE; x++)
		{
			//init + output
			arr2D[y][x] = RANGE_START + rand() % RANGE;
			cout << arr2D[y][x] << " ";

			// minElem + maxElem inital values
			if (y == 0 && x == 0)
			{
				maxElem = arr2D[0][0];
				minElem = arr2D[0][0];
			}

			// maxElem + maxIndexes
			if (arr2D[y][x] > maxElem)
			{
				maxElem = arr2D[y][x];
				maxIndexY = y;
				maxIndexX = x;
			}

			//minElem + minIndexes
			if (arr2D[y][x] < minElem)
			{
				minElem = arr2D[y][x];
				minIndexY = y;
				minIndexX = x;
			}

			// summOfElem
			totalSumm += arr2D[y][x];

			//summOfDiags
			if (x / COEF == y)
				topLeftToBottomRightDiagSumm += arr2D[y][x];

			if (x == X_SIZE - 1 - y / COEF)
				bottomLeftToTopRightDiagSumm += arr2D[y][x];
		}
		cout << endl;
	}

	cout << "Max. elem value is: " << maxElem << " in [" << maxIndexY << "][" << maxIndexX << "]" << endl;
	cout << "Min. elem value is: " << minElem << " in [" << minIndexY << "][" << minIndexX << "]" << endl;
	cout << "Total elems' sum is: " << totalSumm << endl;
	cout << "Top left to bottom right diag summ is: " << topLeftToBottomRightDiagSumm << endl;
	cout << "Bottom left to top right diag summ is: " << bottomLeftToTopRightDiagSumm << endl;


	system("pause");
	return 0;
}