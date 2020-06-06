
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "sequence.h"
#include "signs.h"
#include "def.h"

//const char symbols[MAXSIZE] = { '*', ':', '.', ' ' };

Sign* createSigns(Sequence* pSeq1, Sequence* pSeq2, int n, int size)
{
	int i = 0, temp = 0;
	Sign* signs;

	if ((size) % MAXSIZE > 0) // Checks if there is a need to add 1 more extra byte of data.
		temp = 1;

	signs = (Sign*)malloc(((size) / MAXSIZE + temp) * sizeof(Sign));
	if (!signs)
		return NULL;

	for (; i < size; i++)
	{
		if (pSeq1->seq[n + i] == pSeq2->seq[i]) // If letters are equal.
			insertToSign(signs, i, Asterik);
		else if (checkTable(pSeq1->seq[n + i], pSeq2->seq[i], CLOSE)) // If letters are close.
			insertToSign(signs, i, Colon);
		else if (checkTable(pSeq1->seq[n + i], pSeq2->seq[i], SIMILAR)) // If letters are similar.
			insertToSign(signs, i, Dot);
		else // If letters are none-related.
			insertToSign(signs, i, Space);
	}
	return signs;
}

// Inserts the enum value of a sign into the signs struckt array.
void insertToSign(Sign* signs, int index, int value)
{// Picks the index in the signs array and the sign slot to fill in the struct.
	if (index % MAXSIZE == 0)
		signs[index / MAXSIZE].sign0 = value;
	else if (index % MAXSIZE == 1)
		signs[index / MAXSIZE].sign1 = value;
	else if (index % MAXSIZE == 2)
		signs[index / MAXSIZE].sign2 = value;
	else
		signs[index / MAXSIZE].sign3 = value;
}

// Checks if 2 chars both appear in a certain string (from a set table).
int checkTable(char ch1, char ch2, const char* table)
{
	// if one of the chars does not exist, there is no need to check the whole table.
	if (ch1 == '-' || ch2 == '-')
		return 0;

	char* temp;
	char* delimeters = " ";// Each part of the table is seperated by space (' ').
	temp = _strdup(table); // Duplicating const table.
	temp = strtok(temp, delimeters); // Checking each part of the table.
	while(temp != NULL)
	{
		if (strchr(temp, ch1) != NULL && strchr(temp, ch2) != NULL)
			return 1;
		temp = strtok(NULL, delimeters);
	}

	return 0;
}

//Function for calculating the difference 
//between the number of asteriks(*) to the number of colons(:)
int getCount(Sign* signs, int size)
{
	int countAsteriks = 0;
	int countColons = 0;
	unsigned char uch;
	for (int i = 0; i < size; i++)
	{
		uch = getValueFromSign(signs, i);
		if (uch == Asterik)
			countAsteriks++;
		if (uch == Colon)
			countColons++;
	}

	return countAsteriks - countColons;
}

// returns the value of the a sign by index.
unsigned char getValueFromSign(Sign* signs, int index)
{ // Picks the index in the signs array and the sign slot from the struct to return.
	if (index % MAXSIZE == 0)
		return signs[index / MAXSIZE].sign0;
	else if (index % MAXSIZE == 1)
		return signs[index / MAXSIZE].sign1;
	else if (index % MAXSIZE == 2)
		return signs[index / MAXSIZE].sign2;
	else
		return signs[index / MAXSIZE].sign3;
}

// Setting a signs array and calculating difference between asterisks and colons.
int evaluateDifference(Sequence* pSeq1, Sequence* pSeq2, Sign** signs, int n, int* size)
{
	int diff;

	if (pSeq2->length + n < pSeq1->length) // Checks the size needed for the data.
		*size = pSeq2->length;
	else
		*size = pSeq1->length - n;

	*signs = createSigns(pSeq1, pSeq2, n, *size);

	if (!(*signs))
		return ERROR2;

	diff = getCount(*signs, *size);

	return diff;
}

//Frees memory of sequences and signs.
void freeAll(Sequence* pSeq1, Sequence* pSeq2, Sign* signs, int size)
{
	free(pSeq1->seq);
	free(pSeq2->seq);
	
	free(signs);
}