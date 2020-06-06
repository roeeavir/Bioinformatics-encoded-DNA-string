
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "sequence.h"
#include "def.h"



Sequence* createSequence(char* fileName)
{
	FILE* fp = fopen(fileName, "r"); // Opening file.
	if (!fp)
	{
		printf(FILEERROR);
		return NULL;
	}

	Sequence* pSeq = (Sequence*)malloc(sizeof(Sequence));;
	if (!pSeq)
	{
		fclose(fp);
		return NULL;
	}

	fseek(fp, 0, SEEK_END); // Seeking end of file.

	pSeq->length = ftell(fp);// Setting length of sequence to be the length of the file.

	fseek(fp, 0, SEEK_SET);// Seeking start of file.

	pSeq->seq = (char*)malloc((pSeq->length + 1) * sizeof(char));
	if (!pSeq->seq)
	{
		fclose(fp);
		return NULL;
	}

	fgets(pSeq->seq, pSeq->length + 1, fp);

	fclose(fp);
	return pSeq;
}


