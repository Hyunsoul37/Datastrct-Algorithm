#include <iostream>
using namespace std;

int FindData(int SearchData, int arr[]);
void PrintArray(int arr[]);
void MoveArray(int arr[], int num);

int main()
{
	int i, j;
	int PrevData, CurrentData, SearchData;
	int Arraynum;
	int arr[20] = {};

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		arr[i] = i + 1;
	}

	while (1)
	{
		PrintArray(arr);
		
		cin >> SearchData;

		Arraynum = FindData(SearchData, arr);
		MoveArray(arr, Arraynum);


	}
}

int FindData(int SearchData, int arr[])
{
	int i;

	for (i = 0; i < 20; i++)
	{
		if (arr[i] == SearchData)
		{
			break;
		}

	}

	return i;
}

void PrintArray(int arr[])
{
	int i; 
	for (i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
}

void MoveArray(int arr[], int num)
{
	int i, Data;
	Data = arr[num];
	for (i = num; i >= 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = Data;
}