#include <cstdlib>
#include <cstdio>
#include <Windows.h>
#include "BinarySearch_Score.h"

void QuickSort(Score DataSet[], int Left, int Right);
int Partition(Score DataSet[], int Left, int Right);
void Swap(Score * A, Score * B);

Score * BinarySearch(Score ScoreList[], int Size, double Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = Size - 1;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;

		if (Target == ScoreList[Mid].score)
			return &(ScoreList[Mid]);

		else if (Target > ScoreList[Mid].score)
			Left = Mid + 1;

		else
			Right = Mid - 1;
	}
	return NULL;
}

int CompareScore(const void *_elem1, const void * _elem2)
{
	Score * elem1 = (Score*)_elem1;
	Score * elem2 = (Score*)_elem2;

	if (elem1->score > elem2->score)
		return 1;

	else if (elem1->score < elem2->score)
		return -1;

	else
		return 0;
}

int main()
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;
	Score*found = NULL;

	//qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

	QuickSort(DataSet, 0, Length);

	found = BinarySearch(DataSet, Length, 671.78);

	printf("found : %d %.2f \n", found->number, found->score);

	system("pause");

	return 0;
}


void Swap(Score * A, Score * B)
{
	Score Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(Score DataSet[], int Left, int Right)
{
	int First = Left;
	Score Pivot = DataSet[First];

	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left].score <= Pivot.score && Left < Right)
			++Left;

		while (DataSet[Right].score > Pivot.score && Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(Score DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, index - 1);
		QuickSort(DataSet, index + 1, Right);
	}
}