#include <iostream>
#include <math.h>
#include <time.h>
#include <Windows.h>

using namespace std;

#define S 5

void PrintArray(int** arr, int size1, int size2);


int** GetMemory(int** arr, int rows, int cols)
{
	if (rows == 0 || cols == 0)
	{
		return nullptr;
	}
	if (arr == nullptr)
	{
		arr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
		}
	}
	return arr;
}

int** RemoveRow(int** arr, int* row, int* col, int index)
{
	if (*row != 0 || *col != 0)
	{
		int** temp = nullptr;
		temp = GetMemory(temp, *row, *col);
		for (int i = 0; i < *row; i++)
		{
			for (int j = 0; j < *col; j++)
			{
				temp[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < *row; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;

		int oldRow = *row;
		(*row)--;
		arr = GetMemory(arr, *row, *col);

		int nextI = 0;
		for (int i = 0; i < oldRow; i++)
		{
			//nextI = 0;
			for (int j = 0; j < *col; j++)
			{		
				if (i != index)
				{
					arr[nextI][j] = temp[i][j];
				}
			}
			if (i != index)
			{
				nextI++;
			}
			
		}
	}
	//PrintArray(arr, *row, *col);
	return arr;
}

int** RemoveColumn(int** arr, int* row, int* col, int index)
{
	if (*row != 0 || *col != 0)
	{
		int** temp = nullptr;
		temp = GetMemory(temp, *row, *col);
		for (int i = 0; i < *row; i++)
		{
			for (int j = 0; j < *col; j++)
			{
				temp[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < *row; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;

		int oldCol = *col;
		(*col)--;
		arr = GetMemory(arr, *row, *col);

		int nextJ = 0;
		for (int i = 0; i < *row; i++)
		{
			for (int j = 0; j < oldCol; j++)
			{
				if (j != index)
				{
					arr[i][nextJ] = temp[i][j];
					nextJ++;
					//PrintArray(arr, *row, *col);
				}
			}
			nextJ = 0;
		}
	}
	//PrintArray(arr, *row, *col);
	return arr;
}

int** AddColumn(int** arr, int* row, int* col, int n, int index)
{
	int** temp = nullptr;
	if (*col == 0)
	{
		*row = 1;
		*col = 1;
		arr = new int*[1];
		arr[0] = new int[1];
		arr[0][0] = n;
	}
	else
	{
		//memory
		temp = GetMemory(temp, *row, *col);
		

		//copy
		for (int i = 0; i < *row; i++)
		{
			for (int j = 0; j < *col; j++)
			{
				temp[i][j] = arr[i][j];
			}
			
		}

		//delete original
		for (int i = 0; i < *row; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;
		(*col)++;
		
		arr = GetMemory(arr, *row, *col);


		//copy back to original
		for (int i = 0; i < *row; i++)
		{
			for (int j = 0; j < *col - 1; j++)
			{		
					arr[i][j] = temp[i][j];			
			}
		}

		for (int i = 0; i < *row; i++)
		{
			for (int j = *col - 1; j > index; j--)
			{
				arr[i][j] = arr[i][j - 1];
			}
		}

		for (int i = 0; i < *row; i++)
		{
			arr[i][index] = n;
		}
		
		return arr;
	}
}

int** AddRow(int** arr, int* row, int* col, int n, int index)
{
	int** temp = nullptr;
	if (*col == 0)
	{
		*row = 1;
		*col = 1;
		arr = new int* [1];
		arr[0] = new int[1];
		arr[0][0] = n;
	}
	else
	{
		//memory
		temp = GetMemory(temp, *row, *col);


		//copy
		for (int i = 0; i < *row; i++)
		{
			for (int j = 0; j < *col; j++)
			{
				temp[i][j] = arr[i][j];
			}

		}

		//delete original
		for (int i = 0; i < *row; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;
		(*row)++;

		arr = GetMemory(arr, *row, *col);


		//copy back to original
		for (int i = 0; i < *row - 1; i++)
		{
			for (int j = 0; j < *col; j++)
			{
				arr[i][j] = temp[i][j];
			}
		}

		for (int i = *row - 1; i > index; i--)
		{
			for (int j = 0; j<*col; j++)
			{
				arr[i][j] = arr[i-1][j];
			}
		}

		for (int j = 0; j < *col; j++)
		{
			arr[index][j] = n;
		}

		return arr;
	}
}

void InitArray(int** arr, int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{	
		for (int j = 0; j < size2; j++)
		{
			arr[i][j] = rand() % 10;
		}
		
	}
}

void PrintArray(int** arr, int size1,int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	srand(time(0));

	int rows = 3, cols = 3, n, index;
	int** arr = nullptr;
	bool exit = false;
	char choose;
	
	arr = GetMemory(arr, rows, cols);

	InitArray(arr, rows, cols);
	PrintArray(arr, rows, cols);

	

	while (!exit)
	{
		cout << "What to do?" << endl;
		cout << "a. Add column\nb. Remove column\nc. Add row\nd. Remove row\ne. Exit" << endl;
		cout << "-";
		while (true)
		{
			cin >> choose;
			if ((int)choose >= 97 && (int)choose <= 101)
			{
				break;
			}
			else
			{
				cout << "Incorrect input" << endl;
				cout << "What to do?" << endl;
				cout << "-";
			}
		}


		switch (choose)
		{
			case 'a':
				cout << "Number to fill - ";
				cin >> n;
				cout << "Index to paste - ";
				while (true)
				{
					cin >> index;
					if (index >= 0 && index <= cols)
					{
						break;
					}
					else
					{
						cout << "Incorrect" << endl;
					}
				}
				arr = AddColumn(arr, &rows, &cols, n, index);
				PrintArray(arr, rows, cols);
				break;
			case 'b':
				if (cols != 0)
				{


					cout << "Index to remove - ";
					while (true)
					{
						cin >> index;
						if (index >= 0 && index < cols)
						{
							break;
						}
						else
						{
							cout << "Incorrect" << endl;
						}
					}

					arr = RemoveColumn(arr, &rows, &cols, index);
					PrintArray(arr, rows, cols);
					
				}
				else
				{
					cout << "Massive is already empty" << endl;
				}
				break;
			case 'c':
				cout << "Number to fill - ";
				cin >> n;
				cout << "Index to paste - ";
				while (true)
				{
					cin >> index;
					if (index >= 0 && index <= rows)
					{
						break;
					}
					else
					{
						cout << "Incorrect" << endl;
					}
				}
				arr = AddRow(arr, &rows, &cols, n, index);
				PrintArray(arr, rows, cols);
				break;
			case 'd':
				if (rows != 0)
				{
					cout << "Index to remove - ";
					while (true)
					{
						cin >> index;
						if (index >= 0 && index < rows)
						{
							break;
						}
						else
						{
							cout << "Incorrect" << endl;
						}
					}
					arr = RemoveRow(arr, &rows, &cols, index);
					PrintArray(arr, rows, cols);
					
				}
				else
				{
					cout << "Massive is already empty" << endl;
				}
				break;
			case 'e':
				exit = true;
				break;
		}
	}
}