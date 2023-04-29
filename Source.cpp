#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

#define S 5

void PrintArray(int* p, int size);

int* Delete(int* arr, int* size, int x)
{
	int* temp = new int[*size];
	for (int i = 0; i < *size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	int oldSize = *size;
	(*size)--;

	arr = new int[*size];
	
	int nextI = 0;
	for (int i = 0; i < oldSize; i++)
	{
		if (i != x)
		{
			arr[nextI] = temp[i];
			nextI++;
		}
	}
	delete[] temp;

	cout << "Del - ";
	//PrintArray(arr, *size);
	return arr;
}

int* DeleteArrPovtor(int* arr, int* size) //видаляти по індексу
{
	for (int i = 0; i < *size - 1; i++)
	{
		for (int j = i + 1; j < *size; j++)
		{
			if (arr[i] == arr[j])
			{
				while (arr[i] == arr[j])
				{
					arr = Delete(arr, size,j);
					PrintArray(arr, *size);
				}
			}
		}
	}
	return arr;
}

void InitArray(int* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = rand() % 15;
	}
}

void PrintArray(int* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}


int main()
{
	srand(time(0));
	
	int size = 15;
	int* arr = new int[size];
	InitArray(arr, size);
	PrintArray(arr, size);

	arr = DeleteArrPovtor(arr, &size);
	PrintArray(arr, size);
	delete[] arr;
}