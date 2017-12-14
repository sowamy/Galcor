#include <stdio.h>
#include <stdlib.h>
#include "gDSP.h"

void printSignal(double* sigInc, int a, int b);

int main( void )
{
	double a[8] = {0, 0, 0, 2, -2, 5, 5, -10};
	double* aPtr = &a[0];
	double b[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	double* bPtr = &b[0];

	double* y = sumSignals(aPtr, bPtr, 0, 8);

	printSignal(y, 0, 10);

}

void printSignal(double* sigInc, int a, int b)
{
	// Counters
	int i = 0;
	int j = 0;

	// Iterate through signal until sample <a> is reached
	while( i < a ) {
		sigInc++;
		i++;
	} // END WHILE : Starting position

	// Prints each sample until sample <b> is reached
	while( j < (b - a) ) {
		printf("%d: %.3lf\n", (a + j), *sigInc);
		sigInc++;
		j++;
	} // END WHILE : Print every sample in signal

} // END FUNCTION printSignal
