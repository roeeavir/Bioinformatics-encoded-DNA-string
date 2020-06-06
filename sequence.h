#pragma once

typedef struct
{
	int length;
	char* seq;
} Sequence;


Sequence* createSequence(char* fileName);

