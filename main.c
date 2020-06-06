
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "signs.h"
#include "def.h"
#include "general.h"

int main(int  argc, char*  argv[])
{
	if (argc != 3)// Checks if the number of variables in main is right.
	{
		printf("Error!\n");
		return ERROR;
	}

	Sequence pSeq1, pSeq2;
	Sign* signs;
	int n, diff, size;

	pSeq1 = *createSequence(argv[1]); //Creating sequence 1.
	pSeq2 = *createSequence(argv[2]); //Creating sequence 2.

	n = setNum(pSeq1.length); // Setting n.
	//Setting signs and calculating absolute difference between number of asterisk and colons.
	diff = evaluateDifference(&pSeq1, &pSeq2, &signs, n, &size); 
	if(diff == ERROR2)
	{
		printf("Error!\n");
		return ERROR;
	}

	printf("\nThe difference between asterisks and colons is: %d\n", diff);
	//Macro for printing sequences and signs - depends on "PRINT_SEQUENCES".
	char ch;
	PRINT_SEQUENCES(pSeq1.seq, "\nSequence 1 is:\n\0", SKIP1);
	PRINT_SEQUENCES(pSeq2.seq, "\nSequence 2 is:\n", SKIP1);
	PRINT_SEQUENCES(SKIP2, "\nThe signs are:\n", SKIP1);
	for (int i = 0; i < size; i++)
	{
		ch = symbols[getValueFromSign(signs, i)];
		PRINT_SEQUENCES(SKIP2, SKIP2, ch);
	}

	printf("\n");
	freeAll(&pSeq1, &pSeq2, signs, size);
	system("pause");
}

