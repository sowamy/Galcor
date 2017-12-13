#include <stdio.h>
#include "gDSP.h"

int main( void )
{
	int i = 0;
	int numberOfSamples = 100;
	int delay = 10;
	double energy;
	double *temp;

	PeriodicSignalPtr a;
    a = periodicSignalGenerator(numberOfSamples, delay, 4.0, 0, 0.25);
	temp = a->signal;
	printf("START\n");
	for(i; i < numberOfSamples; i++) {
		printf("%d: %lf\n", i, *temp++);
	}
	printf("END\n");

	energy = signalEnergy(a->signal, 0, 30);

	printf("\nSignal Energy: %lf\n", energy);
    return 0;
}
