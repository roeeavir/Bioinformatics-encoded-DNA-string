#pragma once

// Defines if the sequences and signs will be printed.
#define PRINT
#ifdef PRINT
#define PRINT_SEQUENCES(s1, s2, c)				printf("%s", (s2));		\
												if(c < 0)				\
													printf("%s", (s1));	\
												else					\
													printf("%c", (c));	
#else
#define PRINT_SEQUENCES(s1, s2, c)	printf("")

#endif 


enum SignType { Asterik, Colon, Dot, Space }; // A sign type.

#define FILEERROR "\nCannot open file.\n" // Error message.
#define ERROR -1
#define SKIP1 -1
#define SKIP2 ""
#define ERROR2 -235215215

#define MAXSIZE 4 // Number of signs

#define CLOSE "NDEQ NEQK STA MILV QHRK NHQK FYW HY MILF" //Table of signs.
#define SIMILAR "SAG ATV CSA SGND STPA STNK NEQHRK NDEQHK SNDEQK HFY FVLIM" //Table of signs.
static const char symbols[MAXSIZE] = { '*', ':', '.', ' ' };
