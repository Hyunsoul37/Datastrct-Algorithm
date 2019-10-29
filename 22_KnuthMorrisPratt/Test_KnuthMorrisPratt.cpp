#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "KnuthMorrisPratt.h"

#define MAX_BUFFER 512

int main(int argc, char ** argv)
{
	char* FilePath;
	FILE* fp;

	char Text[MAX_BUFFER];
	char * Pattern;
	int PatternSize = 0;
	int Line = 0;

	/*if (argc < 3)
	{
		printf("Usage : %s <FilePath> <Pattern>\n", argv[0]);
		return 1;
	}

	FilePath = argv[1];
	Pattern = argv[2];*/

	FilePath = (char *)"D:\\Atents\\Algorithm\\20_BruteForce\\BruteForce.cpp";
	Pattern = (char *)"return";

	PatternSize = strlen(Pattern);

	if ((fp = fopen(FilePath, "r")) == NULL)
	{
		printf("Cannot open file : %s\n", FilePath);
	}

	while (fgets(Text, MAX_BUFFER, fp) != NULL)
	{
		int position = KnuthMorrisPratt(Text, strlen(Text), 0, Pattern, PatternSize);

		Line++;

		if (position >= 0)
		{
			printf("line : %d, column : %d : %s", Line, position + 1, Text);
		}
	}

	fclose(fp);

	system("pause");
	return 0;

}