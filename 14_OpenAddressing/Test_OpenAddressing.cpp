#include "OpenAddressing.h"
#include <Windows.h>

int main()
{
	HashTable * HT = OAHT_CreateHashTable(11);

	OAHT_Set(&HT, (char*)"MSFT", (char*)"Microsoft Corporation");
	OAHT_Set(&HT, (char*)"JAVA", (char*)"Sun Microsystems");
	OAHT_Set(&HT, (char*)"REDH", (char*)"Red Hat Linux");
	OAHT_Set(&HT, (char*)"APAC", (char*)"Apache Org");
	OAHT_Set(&HT, (char*)"ZYMZZ", (char*)"Unisys Ops Check");
	OAHT_Set(&HT, (char*)"IBM", (char*)"IBM Ltd");
	OAHT_Set(&HT, (char*)"ORCL", (char*)"Oracle Corporation");
	OAHT_Set(&HT, (char*)"CSCO", (char*)"Cisco System, Inc.");
	OAHT_Set(&HT, (char*)"GOOG", (char*)"Google Inc.");
	OAHT_Set(&HT, (char*)"YHOO", (char*)"Yahoo! Inc.");
	OAHT_Set(&HT, (char*)"NOVL", (char*)"Novell, Inc.");

	printf("\n");

	printf("Key : %s, Value : %s\n", "MSFT", OAHT_Get(HT, (char*)"MSFT"));
	printf("Key : %s, Value : %s\n", "JAVA", OAHT_Get(HT, (char*)"JAVA"));
	printf("Key : %s, Value : %s\n", "REDH", OAHT_Get(HT, (char*)"REDH"));
	printf("Key : %s, Value : %s\n", "APAC", OAHT_Get(HT, (char*)"APAC"));
	printf("Key : %s, Value : %s\n", "ZYMZZ", OAHT_Get(HT, (char*)"ZYMZZ"));
	printf("Key : %s, Value : %s\n", "IBM", OAHT_Get(HT, (char*)"IBM"));
	printf("Key : %s, Value : %s\n", "ORCL", OAHT_Get(HT, (char*)"ORCL"));
	printf("Key : %s, Value : %s\n", "CSCO", OAHT_Get(HT, (char*)"CSCO"));
	printf("Key : %s, Value : %s\n", "GOOG", OAHT_Get(HT, (char*)"GOOG"));
	printf("Key : %s, Value : %s\n", "YHOO", OAHT_Get(HT, (char*)"YHOO"));
	printf("Key : %s, Value : %s\n", "NOVL", OAHT_Get(HT, (char*)"NOVL"));


	OAHT_DestroyHashTable(HT);

	system("pause");
	return 0;

}