//-----------------------------------------------------------------------------------------------------------
// FILE: 							  		gGENERATOR.c
// DESCRIPTION: Generates a series of signal
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
int *gGENERATOR_DCSignalGenerator0( int size, int amplitude, int delay );
double *gGENERATOR_DCSignalGenerator1( int size, double amplitude, int delay );
int *gGENERATOR_DCSignalInserter0( int *signalSource, int index, int sourceSize, int amplitude, int signalSize );
double *gGENERATOR_DCSignalInserter1( double *signalSource, int index, int sourceSize, double amplitude, int signalSize );
int *gGENERATOR_ImpulseSignalGenerator0( int size, int amplitude, int delay );
double *gGENERATOR_ImpulseSignalGenerator1( int size, double amplitude, int delay );
// int *gGENERATOR_ImpulseSignalInserter0( int size, int amplitude, int delay );
// double *gGENERATOR_ImpulseSignalInserter1( int size, double amplitude, int delay );
// int *gGENERATOR_RampSignalGenerator0( int size, int increment, int delay );
// double *gGENERATOR_RampSignalGenerator1( int size, double increment, int delay );
// int *gGENERATOR_RampSignalInserter0( int *signalSource, int index, int sourceSize, int increment, int signalSize );
// double *gGENERATOR_RampSignalInserter1( int *signalSource, int index, int sourceSize, double increment, int signalSize );
// double *gGENERATOR_SineWaveGenerator( );
// double *gGENERATOR_SineWaveInserter( ):
// double *gGENERATOR_CosineWaveGenerator( );
// double *gGENERATOR_CosineWaveInserter( );
// double *gGENERATOR_SquareWaveGenerator( );
// double *gGENERATOR_TriangleWaveGenerator( );
int *gGENERATOR_RandomIntegerSignalGenerator( int size, int minRange, int maxRange );


int *gGENERATOR_DCSignalGenerator0( int size, int amplitude, int delay )
{
    int *dcSignalSource = malloc( (size_t)size ); // Allocate memory for signal
    int *tSignal = dcSignalSource;
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
} // END FUNCTION gGENERATOR_DCSignalGenerator0

double *gGENERATOR_DCSignalGenerator1( int size, double amplitude, int delay )
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
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gGENERATOR_DCSignalInserter0
// DESCRIPTION:
// -- Operates with integers only
// -- Takes an array of integer elements of size <sourceSize> and pointed to by <signal Source>.
// -- Inserts a DC signal into the index value <index> from the signal source.
// -- The DC signal inserted is <signalSize> elements long and has an amplitude of <amplitude>.
// ARGUMENTS:
// -- signalSource  := Pointer to first element in the inputted signal
// -- index         := Index value of where the generated DC signal is inserted
// -- sourceSize    := Size of the original signal inputted
// -- amplitude     := Amplitude of the DC signal inserted
// -- signalSize    := Number of elements in the DC signal inserted
// INTERMEDIATE VARIABLES:
// -- newSignalSource   := Source of the new signal to be returned
// -- newSignalSize     := Size of the new signal to be returned
// -- tSignalSource     := Temporary holder for <signalSource>, to be iterated and operated on
// -- tNewSignalSource  := Temporary holder for <newSignalSource>, to be iterated and operated on
// -- i                 := Counter
// RETURN:
// -- < int * > newSignalSource
// ERROR: NONE
// TESTED: YES - LIMITED
*/
int *gGENERATOR_DCSignalInserter0( int *signalSource, int index, int sourceSize, int amplitude, int signalSize )
{
    int newSignalSize = sourceSize + signalSize;
    int *newSignalSource = malloc( (size_t)newSignalSize );
	int *tSignalSource = signalSource;
	int *tNewSignalSource = newSignalSource;
	int i = 0;

	// Moves to the index location
	for( i = 0; i < index; i++ ) {
        *tNewSignalSource++ = *tSignalSource++;
	} // END for

	// Inserts the DC signal into the indexed location
	for( i = 0; i < signalSize; i++ ) {
        *tNewSignalSource++ = amplitude;
	} // END for

	// Append the new signal with the remainder of the original signal
	for( i = 0; i < ( sourceSize - index ); i++ ) {
        *tNewSignalSource++ = *tSignalSource++;
	} // END for

	// Returns the newly created signal
	return newSignalSource;

} // END FUNCTION gGENERATOR_DCSignalInserter0
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gGENERATOR_DCSignalInserter1
// DESCRIPTION:
// -- Operates with doubleing-point numbers only
// -- Takes an array of elements of size <sourceSize> and pointed to by <signal Source>.
// -- Inserts a DC signal into the index value <index> from the signal source.
// -- The DC signal inserted is <signalSize> elements long and has an amplitude of <amplitude>.
// ARGUMENTS:
// -- signalSource  := Pointer to first element in the inputted signal
// -- index         := Index value of where the generated DC signal is inserted
// -- sourceSize    := Size of the original signal inputted
// -- amplitude     := Amplitude of the DC signal inserted
// -- signalSize    := Number of elements in the DC signal inserted
// INTERMEDIATE VARIABLES:
// -- newSignalSource   := Source of the new signal to be returned
// -- newSignalSize     := Size of the new signal to be returned
// -- tSignalSource     := Temporary holder for <signalSource>, to be iterated and operated on
// -- tNewSignalSource  := Temporary holder for <newSignalSource>, to be iterated and operated on
// -- i                 := Counter
// RETURN:
// -- < double * > newSignalSource
// ERROR: NONE
// TESTED: YES - LIMITED
*/
double *gGENERATOR_DCSignalInserter1( double *signalSource, int index, int sourceSize, double amplitude, int signalSize )
{
    int newSignalSize = sourceSize + signalSize;
    double *newSignalSource = malloc( (size_t)newSignalSize );
	double *tSignalSource = signalSource;
	double *tNewSignalSource = newSignalSource;
	int i = 0;

	// Moves to the index location
	for( i = 0; i < index; i++ ) {
        *tNewSignalSource++ = *tSignalSource++;
	} // END for

	// Inserts the DC signal into the indexed location
	for( i = 0; i < signalSize; i++ ) {
        *tNewSignalSource++ = amplitude;
	} // END for

	// Append the new signal with the remainder of the original signal
	for( i = 0; i < ( sourceSize - index ); i++ ) {
        *tNewSignalSource++ = *tSignalSource++;
	} // END for

	// Returns the newly created signal
	return newSignalSource;

} // END FUNCTION gGENERATOR_DCSignalInserter1
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gGENERATOR_ImpulseSignalGenerator0
// DESCRIPTION:
// -- Consists of integer elements
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
// -- < int * > signalSource
// ERROR: NONE
// TESTED: YES - LIMITED
*/
int *gGENERATOR_ImpulseSignalGenerator0( int size, int amplitude, int delay )
{
	int *signalSource = malloc( (size_t)size );
	if( signalSource == NULL ) {
        printf( "\n\nMALLOC ERROR\n\n" );
        return NULL;
	}
	int *tSignal = signalSource;
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
} // END FUNCTION gGENERATOR_ImpulseSignalGenerator0
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gGENERATOR_ImpulseSignalGenerator1
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
// -- < double * > signalSource
// ERROR: NONE
// TESTED: YES - LIMITED
*/
double *gGENERATOR_ImpulseSignalGenerator1( int size, double amplitude, int delay )
{
	double *signalSource = malloc( (size_t)size );
	if( signalSource == NULL ) {
        printf( "\n\nMALLOC ERROR\n\n" );
        return NULL;
	}
	double *tSignal = signalSource;
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
} // END FUNCTION gGENERATOR_ImpulseSignalGenerator1
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gGENERATOR_RandomIntegerSignalGenerator
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
int *gGENERATOR_RandomIntegerSignalGenerator( int size, int minRange, int maxRange )
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
} // END FUNCTION gGENERATOR_RandomIntegerSignalGenerator
//-----------------------------------------------------------------------------------------------------------
