#include <stdio.h>
#include <gECON.h>

int main( void )
{
    BEP answer = gECON_BreakEvenPoints( 180, 0.02, 83, 73000 );
    printf( "%.2f - %.2f", answer.low, answer.high );
    return 0;
}
