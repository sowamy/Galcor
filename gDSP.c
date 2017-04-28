//-----------------------------------------------------------------------------------------------------------
// FILE: 							  		gDSP.c
// DESCRIPTION: Contains a multitude of Digital Signal Processing functionalities
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
double *gDSP_DCSignalGenerator( int size, double amplitude, int delay );
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gDSP_DCSignalGenerator
// DESCRIPTION:
// -- Generates a constant DC signal of length <samples>
// -- Returns pointer to the location of the generated DC signal
// ARGUMENTS:
// -- samples           := Number of samples of the full signal to be created and returned
// -- amplitude         := The amplitude of the DC signal
// -- delay             := Number of samples the DC signal is delayed from time 0
// INTERMEDIATE VARIABLES:
// -- dcSignalSource    := Pointer to first element of signal
// -- tSignal           := Temporary pointer used to offset the signal during stimulation
// -- i, j              := Counters
// RETURN:
// -- < double > dcSignalSource
// ERROR:
// -- delay > size
// TESTED: YES
// RESULTS: PASSED
*/
double *gDSP_DCSignalGenerator( int size, double amplitude, int delay )
{
    double *dcSignalSource = malloc( (size_t)size ); // Allocate memory for signal
    double *tSignal = dcSignalSource;
    int i = 0;
    int j = 0;

    // Create delay in signal
    for( j = 0; j < delay; j++ ) {
            *tSignal = 0;
            tSignal++;
    } // END for

    // Stimulates DC signal
    for( i = 0; i < size; i++ ) {
        *tSignal = amplitude;
        tSignal++;
    } // END for

    return dcSignalSource;
}
//-----------------------------------------------------------------------------------------------------------
