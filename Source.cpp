#include <iostream>
#include <algorithm>
#include <utility>
#include <ctime>

using namespace std;


void dataInput(int& const row, int& const col)
{
	cout << "Enter number of rows:" << endl;
	cin >> row;

	cout << "Enter number of columns:" << endl;
	cin >> col;

	cout << endl << endl;
}

int** createArray(int row, int col)
{
	int** arr = new int* [row];

	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	return arr;
}

void fillArray(int** arr, int row, int col)
{
	srand(time(NULL));

	int kolychestvoElementov = row * col;
	bool ujeTut = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; )
		{
			int newRandomValue = 1 + (rand() % kolychestvoElementov);
			ujeTut = true;

			for (int m = 0; m <= i; m++)
			{
				for (int n = 0; n < col; n++)
				{
					if (arr[m][n] == newRandomValue)
					{
						ujeTut = false;
						break;
					}
				}

				if (ujeTut == false)
				{
					break;
				}
			}

			if (ujeTut == true)
			{
				arr[i][j] = newRandomValue;
				j++;
			}
		}
	}
}

int** copyArray(int** arr, int row, int col)
{
	int** copyArr = new int* [row];

	for (int i = 0; i < row; i++)
	{
		copyArr[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			copyArr[i][j] = arr[i][j];
		}
	}
	return copyArr;
}

void printArray(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl << endl << endl;
	}

	cout << endl << endl;
}

void sortingAnArrayBySelectionMethod(int** arr, int row, int col)
{
	int iteration = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			bool sorted = true;
			int minElemArr, copyIteration, ii, jj;
			
			minElemArr = arr[i][j];

			iteration++;
			copyIteration = iteration;

			for (int m = 0; m < row; m++)
			{
				for (int n = 0; n < col; n++)
				{
					copyIteration--;

					if (copyIteration >= 0)
					{
						continue;
					}

					if (arr[m][n] < minElemArr)
					{
						minElemArr = arr[m][n];
						ii = m;
						jj = n;
						sorted = false;
					}
				}
			}

			if (sorted == false)
			{
				swap(arr[i][j], arr[ii][jj]);
			}

			if (iteration == row * col)
			{
				break;
			}
		}

		if (iteration == row * col)
		{
			break;
		}
	}
}

void bubbleSortArray(int** copyArr, int row, int col)
{
	for (int k = 0; k < row; k++)
	{
		for (int l = 0; l < col; l++)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (i == row - 1 && j == col - 1)
					{
						break;
					}

					else
					{
						if (j == col - 1)
						{
							if (copyArr[i][j] > copyArr[i + 1][0])
							{
								swap(copyArr[i][j], copyArr[i + 1][0]);
							}
						}

						else
						{
							if (copyArr[i][j] > copyArr[i][j + 1])
							{
								swap(copyArr[i][j], copyArr[i][j + 1]);
							}
						}
					}
				}
			}
		}
	}
}

void deleteArray(int** arr, int** copyArr, int row)
{
	if (arr)
	{
		for (int i = 0; i < row; i++)
		{
			if (arr[i])
			{
				delete[] arr[i];
			}
		}

		delete[] arr;
	}

	if (copyArr)
	{
		for (int i = 0; i < row; i++)
		{
			if (copyArr[i])
			{
				delete[] copyArr[i];
			}
		}

		delete[] copyArr;
	}
}

int main()
{
	int row, col;

	dataInput(row, col);

	int** arr = createArray(row, col);

	fillArray(arr, row, col);

	int** copyArr = copyArray(arr, row, col);

	cout << "Original array:" << endl << endl;
	printArray(arr, row, col);

	sortingAnArrayBySelectionMethod(arr, row, col);

	cout << "Sorting array by selection method:" << endl << endl;
	printArray(arr, row, col);

	cout << "Original array:" << endl << endl;
	printArray(copyArr, row, col);

	bubbleSortArray(copyArr, row, col);

	cout << "Bubble sort array:" << endl << endl;
	printArray(copyArr, row, col);

	deleteArray(arr, copyArr, row);

	return 0;
}



