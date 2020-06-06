
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "general.h"

// Setting a number to be in a certain range.
int setNum(int size)
{
	int n;
	printf("Set number n ");
	printf("start of comperasion, cannot be lower than the size of seq1 - %d\n",
		size);

	do { // Setting n.
		scanf("%d", &n);
		if (n > size)
			printf("\nBad input!\nn cannot be higher than the sequence size!\nTry again!\n");
		else if (n < 0)
			printf("\nBad input!\nn cannot be lower than 0!\nTry again!\n");
	} while (n > size || n < 0);

	return n;
}