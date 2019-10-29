#include "Chaining.h"
#include <Windows.h>

int main()
{
	HashTable * HT = CHT_CreateHashTable(12289);

	CHT_Set(HT, (char*)"MSFT", (char*)"Microsoft Corporation");
	CHT_Set(HT, (char*)"JAVA", (char*)"Sun Microsystems");
	CHT_Set(HT, (char*)"REDH", (char*)"Red Hat Linux");
	CHT_Set(HT, (char*)"APAC", (char*)"Apache Org");
	CHT_Set(HT, (char*)"ZYMZZ", (char*)"Unisys Ops Check");
	CHT_Set(HT, (char*)"IBM", (char*)"IBM Ltd");
	CHT_Set(HT, (char*)"ORCL", (char*)"Oracle Corporation");
	CHT_Set(HT, (char*)"CSCO", (char*)"Cisco System, Inc.");
	CHT_Set(HT, (char*)"GOOG", (char*)"Google Inc.");
	CHT_Set(HT, (char*)"YHOO", (char*)"Yahoo! Inc.");
	CHT_Set(HT, (char*)"NOVL", (char*)"Novell, Inc.");

	printf("\n");

	printf("Key : %s, Value : %s\n", "MSFT", CHT_Get(HT, (char*)"MSFT"));
	printf("Key : %s, Value : %s\n", "JAVA", CHT_Get(HT, (char*)"JAVA"));
	printf("Key : %s, Value : %s\n", "REDH", CHT_Get(HT, (char*)"REDH"));
	printf("Key : %s, Value : %s\n", "APAC", CHT_Get(HT, (char*)"APAC"));
	printf("Key : %s, Value : %s\n", "ZYMZZ", CHT_Get(HT, (char*)"ZYMZZ"));
	printf("Key : %s, Value : %s\n", "IBM", CHT_Get(HT, (char*)"IBM"));
	printf("Key : %s, Value : %s\n", "ORCL", CHT_Get(HT, (char*)"ORCL"));
	printf("Key : %s, Value : %s\n", "CSCO", CHT_Get(HT, (char*)"CSCO"));
	printf("Key : %s, Value : %s\n", "GOOG", CHT_Get(HT, (char*)"GOOG"));
	printf("Key : %s, Value : %s\n", "YHOO", CHT_Get(HT, (char*)"YHOO"));
	printf("Key : %s, Value : %s\n", "NOVL", CHT_Get(HT, (char*)"NOVL"));

	system("pause");

	CHT_DestroyHashTable(HT);

	return 0;

}