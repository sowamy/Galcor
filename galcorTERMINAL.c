
//-----------------------------------------------------------------------------------------------------------
//                    FILE: galcorTERMINAL
//-----------------------------------------------------------------------------------------------------------
/*
DESCRIPTION:
    - Runs a terminal based GUI which interacts with
      Galcor's primary modules
*/
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
void gTERMINAL_Start( void );
//-----------------------------------------------------------------------------------------------------------
/*
FUNCTION:       gTERMINAL_START
DESCRIPTION:    Starts the terminal based GUI
ARGUMENTS:      None
*/
void gTERMINAL_Start( void )
{
    int menuChoice = 0; // Stores user choice to main menu

    // Print main menu onto screen
    printf( "           ***GALCOR 1.0***   \n\n\n" );
    printf( "MAIN MENU\n" );
    printf( "\t1.NEW OPERATION\n" );
    printf( "\t2.EXIT\n\n--> " );
    scanf( "%d", &menuChoice );
} // END FUNCTION gTERMINAL_Start()
//-----------------------------------------------------------------------------------------------------------
