float g_SumArray( const int *array_in, int size );

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
