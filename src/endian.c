// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextFloat()
//      * printNumberData()

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// report whether machine is big or small endian
void bigOrSmallEndian()
{
	unsigned int n = 1;
	char *a = (char*)&n;
	if (*a)
	{	
		printf("byte order: little-endian\n");
	}
	else
	{
		printf("byte order: big-endian\n");
	}
	printf("\n");
}

// get next float using scanf()
// returns true (success) or false (failure)
// if call succeeded, return float value via fPtr
bool getNextFloat(float *fPtr)
{
	float temp = 0;
	char c;
	if (scanf("%f", &temp) == 1)
	{
		*fPtr = temp;
		return true;
	}
	else
	{
		while ((c = getchar()) != '\n' && c != EOF);
		return false;
	}
}

// print requested data for the given number
void printNumberData(float f)
{
    	unsigned int i = f;
	printf("%10d ", i);
	printf("%#010X\n", i);
	printf("%10.2f ", f);
	printf("%#010X\n", *(unsigned int*)&f);
}

// do not change this function in any way, except for adding your name
int main(int argc, char **argv)
{
    float	f;	                        // currently being analyzed
    bool	validInput;			// was user input valid?

    printf("Programmed by Adam La Fleur for CS201\n\n");
    bigOrSmallEndian();

    do {
	if (argc == 1)				// allow grading script to control ...
	    printf("> ");			// ... whether prompt character is printed

	validInput = getNextFloat(&f);

	if (! validInput) {			// encountered bad input
	    printf("bad input\n");
	} else {
	    printNumberData(f);
	}

    } while (!validInput || f != 0.0);

    printf("\n");
    return 0;
}
