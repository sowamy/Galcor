#include <stdio.h>
#include <stdlib.h>
#include "gDSP.h"

int main( void )
{
	double a[8] = {0, 0, 0, 2, -2, 5, 5, 10};
	double* b = &a[0];

	SignalPtr s = getSignalAttributes(b, 8);
	printf("\nDelay: %d\n", s->delay);
	printf("Max Amplitude: %lf\n", s->maxAmplitude_pos);
	printf("Min Amplitude; %lf\n", s->maxAmplitude_neg);
	printf("Energy: %lf\n", s->totalEnergy);
	printf("Power: %lf\n", s->totalPower);
    return 0;
}
