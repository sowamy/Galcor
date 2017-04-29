//-----------------------------------------------------------------------------------------------------------
// FILE: 			gDSP.c
// DESCRIPTION: Contains a multitude of Digital Signal Processing functionalities
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
float *gDSP_DCSignalGenerator( int size, float amplitude, int delay );
float *gDSP_ImpulseSignalGenerator( int size, float amplitude, int delay );
int *gDSP_RandomIntegerSignalGenerator( int size, int minRange, int maxRange );
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
// -- < float * > dcSignalSource
// TESTED: YES - LIMITED
*/
float *gDSP_DCSignalGenerator( int size, float amplitude, int delay )
{
    float *dcSignalSource = malloc( (size_t)size ); // Allocate memory for signal
    float *tSignal = dcSignalSource;
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
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gDSP_ImpulseSignalGenerator
// DESCRIPTION:
// -- Returns the pointer <signalSource> which points to the address of the signal generated.
// -- The signal generated is of size <size>, and has an impulse of amplitude <amplitude>,
//      at <delay> samples from TIME 0
// ARGUMENTS:
// -- size          := Size of the signal to be generated
// -- amplitude     := Amplitude of the impulse signal to be generated
// -- delay         := Number of samples from TIME 0 that the impulse signal will be generated
// INTERMEDIATE VARIABLES:
// -- signalSource  := Source of the signal to be generated
// -- tSignal       := Temporary pointer used to offset the signal during stimulation
// -- i             := Counter
// RETURN:
// -- < float * > signalSource
// ERROR: NONE
// TESTED: YES - LIMITED
*/
float *gDSP_ImpulseSignalGenerator( int size, float amplitude, int delay )
{
	float *signalSource = malloc( (size_t)size );
	if( signalSource == NULL ) {
        printf( "\n\nMALLOC ERROR\n\n" );
        return NULL;
	}
	float *tSignal = signalSource;
	int i = 0;

	for( i = 0; i < size; i++ ) {
        if( i == delay ) {
            *tSignal = amplitude;
            tSignal++;
        } else {
            *tSignal = 0;
            tSignal++;
        } // END if...else
	} // END for

	return signalSource;
} // END FUNCTION gDSP_ImpulseSignalGenerator
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gDSP_RandomIntegerSignalGenerator
// DESCRIPTION:
// -- Returns an integer pointer with the address to the first element in an array of random integers
// --   between the values minRange and maxRange.
// ARGUMENTS:
// -- size          := Number of samples of the signal to be generated
// -- minRange      := Lowest value to be generated
// -- maxRange      := Highest value to be generated
// INTERMEDIATE VARIABLES:
// -- signalSource  := Address to first element of the signal
// -- currentPtr    := Pointer used to iterate and insert elements into the array
// -- value         := Random value to put into each element
// -- difference    := Difference between maxRange and minRange
// -- i             := Counter
// RETURN:
// -- < int >  signalSource
// ERROR: NONE
// TESTED: YES - LIMITED
*/
int *gDSP_RandomIntegerSignalGenerator( int size, int minRange, int maxRange )
{
    srand( time( NULL ) );
    int i = 0;
    int value = 0;
    int *sourcePtr = malloc( (size_t)size );
    if( sourcePtr == NULL ) {
            printf( "MALLOC ERROR" );
            return NULL;
        }
    int *currentPtr = sourcePtr;
    int difference = maxRange - minRange;

    for( i = 0; i < size; i++ ) {
        value = rand() % ( difference + 1 );
        *currentPtr++ = value + minRange;
    } // END for

    return sourcePtr;
} // END FUNCTION gDSP_RandomIntegerSignalGenerator
//-----------------------------------------------------------------------------------------------------------
