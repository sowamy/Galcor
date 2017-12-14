#include <stdio.h>
#include <stdlib.h>
#include "gDSP.h"

int main( void )
{
	double a[8] = {0, 0, 0, 2, -2, 5, 5, -10};
	double* b = &a[0];

	SignalPtr s = getSignalAttributes(b, 8);
	printf("\nDelay: %d\n", s->delay);
	printf("Max Amplitude: %lf\n", s->maxAmplitude_pos);
	printf("Min Amplitude; %lf\n", s->maxAmplitude_neg);
	printf("Energy: %lf\n", s->totalEnergy);
	printf("Power: %lf\n", s->totalPower);

	// Switch Limits Test
	printf( "\nEnergy_Test: %lf\n", signalEnergy(s->signal, 5, 2));
	printf( "Power_Test: %lf\n", signalPower(s->signal, 5, 2));

	// Type Test
	// printf( "\nEnergy_Test: %lf\n", signalEnergy(s->signal, a, 2));
	// printf( "\nPower_Test: %lf\n", signalPower(s->signal, a, 2));

	// Out of range Test
	printf( "\nEnergy_Test: %lf\n", signalEnergy(s->signal, 5, 9));
	printf( "Power_Test: %lf\n", signalPower(s->signal, 5, 9));
	printf( "\nEnergy_Test: %lf\n", signalEnergy(s->signal, 5, 10));
	printf( "Power_Test: %lf\n", signalPower(s->signal, 5, 10));
	printf( "\nEnergy_Test: %lf\n", signalEnergy(s->signal, 5, 11));
	printf( "Power_Test: %lf\n", signalPower(s->signal, 5, 11));
	printf( "\nEnergy_Test: %lf\n", signalEnergy(s->signal, -5, 10));
	printf( "Power_Test: %lf\n", signalPower(s->signal, -5, 10));
    return 0;
}
