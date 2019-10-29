#include "TransposeMethod.h"

void MakeArray(int arr[])
{
	int i; 
	for (i = 0; i < 20; i++)
	{
		arr[i] = i + 1;
	}
}

void PrintArray(int arr[])
{
	int i;

	for (i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int FindData(int SearchData, int arr[])
{
	int i;

	for (i = 0; i < 20; i++)
	{
		if (arr[i] == SearchData)
			break;
	}

	return i;
}

void MoveArray(int arr[], int SearchNumber)
{
	int temp;

	temp = arr[SearchNumber];
	arr[SearchNumber] = arr[SearchNumber - 1];
	arr[SearchNumber - 1] = temp;

}