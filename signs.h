#pragma once

#include "sequence.h"

typedef struct
{
	unsigned char sign0 : 2;
	unsigned char sign1 : 2;
	unsigned char sign2 : 2;
	unsigned char sign3 : 2;
}Sign ;


Sign* createSigns(Sequence* pSeq1, Sequence* pSeq2, int n, int size);

void insertToSign(Sign* signs, int index, int value);

int checkTable(char ch1, char ch2, const char* table);

int getCount(Sign* signs, int size);

unsigned char getValueFromSign(Sign* signs, int index);

int evaluateDifference(Sequence* pSeq1, Sequence* pSeq2, Sign** signs, int n, int* size);

void freeAll(Sequence* pSeq1, Sequence* pSeq2, Sign* signs, int size);
