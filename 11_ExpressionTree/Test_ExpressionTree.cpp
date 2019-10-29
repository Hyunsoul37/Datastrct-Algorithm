#include "ExpressionTree.h"

int main()
{
	ETNode* Root = NULL;

	char PostfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(PostfixExpression, &Root);

	printf("Preoder ... \n");
	ET_PreorderPrintTree(Root);
	printf("\n\n");

	printf("Inoder ... \n");
	ET_InorderPrintTree(Root);
	printf("\n\n");

	printf("Postoder ... \n");
	ET_PostorderPrintTree(Root);
	printf("\n");

	printf("\nEvaulation Result : %f \n", ET_Evaluate(Root));

	ET_DestroyTree(Root);

	return 0;
}