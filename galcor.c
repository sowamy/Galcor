/*
FILE: galcor.c
DESCRIPTION:
    - Holds general functionality of the galcor program, key modules.
*/
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
float g_Sum( const int *array_in, int size );
float g_Average( const int *array_in, int size );
void g_IntInsertionSort( int *inputArrayPtr, int size );
void g_FloatInsertionSort( int *inputArrayPtr, int size );
//-----------------------------------------------------------------------------------------------------------
/*
FUNCTION: g_Sum
DESCRIPTION:
    - Sums elements in array pointed to by <array_in> of size <size>
    - Returns a float representing the sum of all the elements in the array
ARGUMENTS:
    IN:
    - *array_in     := Pointer pointing to first element in the array to be summed
    - size          := Size of the array to be summed
    OUT:
    - < float >     := Sum of all elements in the array
TESTED: NO
*/
float g_Sum( const int *array_in, int size )
{
    float sum = 0;
    int counter = 0;
    int *arrayPtr = array_in;

    for( counter = 0; counter < size; counter++ ) {
        sum += *arrayPtr;
        arrayPtr++;
    } // END for

    return sum;
} // END FUNCTION g_SUM
//-----------------------------------------------------------------------------------------------------------
/*
FUNCTION: g_Average
DESCRIPTION:
    - Sums all of the elements in array pointed to by <array_in> and divides it by the size of the array <size>
    - Returns the average calculated as a float value
ARGUMENTS:
    IN:
    - *array_in     := Pointer to address of the first element in the array to be averaged
    - size          := Size of the array to be averaged
    OUT:
    - < float >     := Average of the array
TESTED: NO
*/
float g_Average( const int *array_in, int size )
{
    float avg = 0;
    float sum = 0;
    int counter = 0;
    int *arrayPtr = array_in;

    sum = g_SumArray( array_in, size );
    avg = sum / size;

    return avg;
} // END FUNCTION g_Average
//-----------------------------------------------------------------------------------------------------------
/*
FUNCTION: g_IntInsertionSort
DESCRIPTION:
    - Sorts an array of integers pointed to by < inputArrayPtr> and is of size < size >
    - Sorts the elements in the array pointed to itself
    - DO NOT PASS CONSTANT ARRAY
ARGUMENTS:
    IN:
    - *inputArrayPtr    := The pointer to the first element in the array to be sorted
    - size              := Size of the array to be sorted
    OUT: None
TESTED: NO
*/
void g_IntInsertionSort( int *inputArrayPtr, int size )
{
    int *tempPtr = inputArrayPtr;   // Temporary array pointer
    int a[ size ];                  // Temporary array to do the sort on

    int i = 0;                      // Counter
    int j = 0;                      // Counter
    int key = 0;                    // Holder to be used during sorting

    // Clones array in original array address
    for( i = 0; i < size; i++ ) {
        a[ i ] = *tempPtr++;
    } // END for

    // Insertion sort
    for( j = 1; j < 10; j++ ) {
        key = a[ j ];
        i = j - 1;
        while( ( i >= 0 ) && ( a[ i ] > key ) ) {
            a[ i + 1 ] = a[ i ];
            i = i - 1;
        } // END while
        a[ i + 1 ] = key;
    } // END for

    i = 0;
    tempPtr = inputArrayPtr;

    // Putting sorted array into the address of the original array
    for( i = 0; i < 10; i++ ) {
        *tempPtr++ = a[ i ];
    } // END for
} // END FUNCTION g_IntInsertionSort
//-----------------------------------------------------------------------------------------------------------
/*
FUNCTION: g_FloatInsertionSort
DESCRIPTION:
    - Sorts an array of integers pointed to by < inputArrayPtr> and is of size < size >
    - Sorts the elements in the array pointed to itself
    - DO NOT PASS CONSTANT ARRAY
ARGUMENTS:
    - *inputArrayPtr    := Pointer to first element of array to be sorted
    - size              := Size of array to be sorted
TESTED: NO
*/
void g_FloatInsertionSort( int *inputArrayPtr, int size )
{
    int *tempPtr = inputArrayPtr;    // Temporary pointer
    int a[ size ];                   // Temporary array to do the sort on

    int i = 0;                       // Counter
    int j = 0;                       // Counter
    float key = 0;                   // Used in insertion sort

    // Creation of temporary array to be used in sorting
    for( i = 0; i < size; i++ ) {
        a[ i ] = *tempPtr++;
    } // END for

    // Insertion sort
    for( j = 1; j < 10; j++ ) {
        key = a[ j ];
        i = j - 1;
        while( ( i >= 0 ) && ( a[ i ] > key ) ) {
            a[ i + 1 ] = a[ i ];
            i = i - 1;
        } // END while
        a[ i + 1 ] = key;
    } // END for

    i = 0;
    tempPtr = inputArrayPtr;

    // Inserting sorted array into address of original array
    for( i = 0; i < 10; i++ ) {
        *tempPtr++ = a[ i ];
    } // END for
} // END FUNCTION g_FloatInsertionSort
//-----------------------------------------------------------------------------------------------------------
