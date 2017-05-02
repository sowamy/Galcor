//-----------------------------------------------------------------------------------------------------------
//                    FILE: galcorCONTROLLER.c
//-----------------------------------------------------------------------------------------------------------
/*
DESCRIPTION:
    - Handles the interactions between the formulas and the results they provide
    - Is an extra layer on top of the bare formulas to enhance their use
*/
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <gTERMINAL.h>
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
void gCONTROLLER_RunInTerminal( void );
//-----------------------------------------------------------------------------------------------------------
/*
FUNCTION: gCONTROLLER_RunInTERMINAL()
DESCRIPTION:
    - Runs terminal based GUI
ARGUMENTS: NONE
TESTED: NO
*/
void gCONTROLLER_RunInTerminal( void )
{
    gTERMINAL_Start();
} // END FUNCTION gCONTROLLER_RunInTerminal
//-----------------------------------------------------------------------------------------------------------
