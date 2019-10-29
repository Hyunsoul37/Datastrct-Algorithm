#pragma once
#include <stdio.h>

int KnuthMorrisPratt(char * Text, int TextSize, int Start, char * Pattern, int PatternSize);
void Preprocess(char * Patter, int PatternSize, int * Border);