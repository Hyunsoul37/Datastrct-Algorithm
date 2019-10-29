#include "TransposeMethod.h"

int main()
{
	int arr[20] = {};
	int SearchData;
	int Location;

	MakeArray(arr);

	while (1)
	{
		PrintArray(arr);

		cin >> SearchData;

		Location = FindData(SearchData, arr);

		MoveArray(arr, Location);
	}
}