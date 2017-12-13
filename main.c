#include <stdio.h>
#include "gDSP.h"

int main( void )
{
	int i = 0;
	int numberOfSamples = 100;
	int delay = 10;
	PeriodicSignalPtr a;
    a = periodicSignalGenerator(numberOfSamples, delay, 10.0, PI, 0.05);
	printf("START\n");
	for(i; i < numberOfSamples; i++) {
		printf("%d: %lf\n", i, *a->signal++);
	}
	printf("END\n");
    return 0;
}
