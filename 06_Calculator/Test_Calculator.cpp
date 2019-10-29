#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <String>
#include "Calculator.h"

int main()
{
	char InfixExpression[100];
	char PostfixExpression[100];

	double Result = 0.0;

	memset(InfixExpression, 0, sizeof(InfixExpression));
	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	printf("Enter Infix Expression : ");
	scanf("%s", InfixExpression);

	GetPostfix(InfixExpression, PostfixExpression);

	printf("Infix:%s\nPostfix:%s\n",
		InfixExpression, PostfixExpression);

	Result = Calculate(PostfixExpression);

	printf("Calculation Result : %f\n", Result);

	system("pause");

	return 0;
}