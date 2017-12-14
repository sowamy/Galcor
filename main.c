#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

	double *b = (double *) malloc(sizeof(double)*3);
	double *bTemp = b;
	*bTemp = 2.0;
	bTemp++;
	*bTemp = 4.0;
	bTemp++;
	*bTemp = 6.0;


	printf( "\nEnergy: %lf\n", signalEnergy(b, 0, 2) );
	printf( "\nPower: %lf\n", (signalEnergy(b, 0, 2) / 3) );
	printf( "\nPower: %lf\n", signalPower(b, 0, 2) );
    return 0;
}
