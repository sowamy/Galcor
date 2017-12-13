#include <stdio.h>
#include "gDSP.h"

int main( void )
{
	int i = 0;
	PeriodicSignalPtr a;
    a = periodicSignalGenerator(10, 1, 10.0, 0.0, 0.05);
	printf("START\n");
	for(i; i < 10; i++) {
		printf("%d: %lf\n", i, *a->signal++);
	}
	printf("END\n");
    return 0;
}

