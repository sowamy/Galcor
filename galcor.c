float g_SumArray( const int *array_in, int size );
float g_AvgArray( const int *array_in, int size );
void g_IntInsertionSort( int *inputArrayPtr, int size );
void g_FloatInsertionSort( int *inputArrayPtr, int size );

float g_SumArray( const int *array_in, int size )
{
    float sum = 0;
    int counter = 0;
    int *arrayPtr = array_in;

    for( counter = 0; counter < size; counter++ ) {
        sum += *arrayPtr;
        arrayPtr++;
    }

    return sum;
}

float g_AvgArray( const int *array_in, int size )
{
    float avg = 0;
    float sum = 0;
    int counter = 0;
    int *arrayPtr = array_in;

    sum = g_SumArray( array_in, size );
    avg = sum / size;

    return avg;
}

void g_IntInsertionSort( int *inputArrayPtr, int size )
{
    int *tempPtr = inputArrayPtr;
    int a[ size ];         // Temporary array to do the sort on

    int i = 0;
    int j = 0;
    int key = 0;

    for( i = 0; i < size; i++ ) {
        a[ i ] = *tempPtr++;
    }

    for( j = 1; j < 10; j++ ) {
        key = a[ j ];
        i = j - 1;
        while( ( i >= 0 ) && ( a[ i ] > key ) ) {
            a[ i + 1 ] = a[ i ];
            i = i - 1;
        }
        a[ i + 1 ] = key;
    }

    i = 0;
    tempPtr = inputArrayPtr;

    for( i = 0; i < 10; i++ ) {
        *tempPtr++ = a[ i ];
    }
} // END FUNCTION g_IntInsertionSort

void g_FloatInsertionSort( int *inputArrayPtr, int size )
{
    int *tempPtr = inputArrayPtr;
    int a[ size ];         // Temporary array to do the sort on

    int i = 0;
    int j = 0;
    float key = 0;

    for( i = 0; i < size; i++ ) {
        a[ i ] = *tempPtr++;
    }

    for( j = 1; j < 10; j++ ) {
        key = a[ j ];
        i = j - 1;
        while( ( i >= 0 ) && ( a[ i ] > key ) ) {
            a[ i + 1 ] = a[ i ];
            i = i - 1;
        }
        a[ i + 1 ] = key;
    }

    i = 0;
    tempPtr = inputArrayPtr;

    for( i = 0; i < 10; i++ ) {
        *tempPtr++ = a[ i ];
    }
} // END FUNCTION g_FloatInsertionSort
