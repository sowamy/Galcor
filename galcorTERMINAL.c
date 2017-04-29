
//-----------------------------------------------------------------------------------------------------------
//                    FILE: galcorTERMINAL
//-----------------------------------------------------------------------------------------------------------
/*
DESCRIPTION:
    - Runs a terminal based GUI which interacts with Galcor's primary modules
*/
//-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//-----------------------------------------------------------------------------------------------------------
// Structure and Type Definitions
//-----------------------------------------------------------------------------------------------------------
// Menu Structure
struct menuFormat {
    char *title;    // Title of the menu
    char *opt1;     // Menu option 1
    char *opt2;     // Menu option 2 ...
    char *opt3;
    char *opt4;
    char *opt5;
    char *opt6;
    char *opt7;
    char *opt8;
    char *opt9;
};
// Menu Type Definitions
typedef struct menuFormat menu; // Creates a type menu which represents structure menuFormat
typedef menu menuPtr;           // Creates a pointer which points to menuPtr
//-----------------------------------------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------------------------------------
void gTERMINAL_Start( void );
void gTERMINAL_PrintTitle( void );
int gTERMINAL_PrintMenu( menuPtr *inMenu );
menuPtr *gTERMINAL_InitializeMenu( char title[ 20 ],
                                    char option1[ 20 ], char option2[ 20 ], char option3[ 20 ],
                                    char option4[ 20 ], char option5[ 20 ], char option6[ 20 ],
                                    char option7[ 20 ], char option8[ 20 ], char option9[ 20 ] );
void gTERMINAL_PrintIntegerArray( int *source, int size );
void gTERMINAL_PrintFloatArray( float *source, int size );
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gTERMINAL_Start
// DESCRIPTION:
// -- Starts the terminal GUI which will interact with the Galcor core modules
// ARGUMENTS: NONE
// INTERMEDIATE VARIABLES:
// -- guiON         := Boolean which when false, turns off the GUI and ends the program
// -- state         := Controls the display of specific menu and its operations
// -- menuChoice    := Response from the user to the menu prompt
// MENUS:
// -- mainMenu          := Home menu and the base of operations
// -- operationsMenu    := Perform basic operations
// STATES:
// -- 00 := Home Menu
// -- 01 := Operations Menu
// -- 02 := Leaf Menu
// RETURN: NONE
// ERROR: NONE
// TESTED: YES - LIMITED
*/
void gTERMINAL_Start( void )
{
    bool guiON = true;
    int state = 0;
    int menuChoice = 0;

    // Initialize menu pointers and data
    menuPtr *mainMenu = gTERMINAL_InitializeMenu( "HOME", "NEW OPERATION", "LEAFS", NULL, NULL,
                                                  NULL, NULL, NULL, NULL, NULL );
    menuPtr *operationsMenu = gTERMINAL_InitializeMenu( "OPERATIONS", "NEW OPERATION", "LEAFS", NULL, NULL,
                                                  NULL, NULL, NULL, NULL, NULL );

    // Main GUI loop
    while( guiON == true ) {
        switch( state ) {
        case 00:
            system( "cls" );
            gTERMINAL_PrintTitle();
            menuChoice = gTERMINAL_PrintMenu( mainMenu );
            if( menuChoice == 0 ) { guiON = false; }
            break;
        default:
            printf( "Error" );
        } // END case
    } // END while

    // Free menu pointers and data
    free( mainMenu );

} // END FUNCTION gTERMINAL_Start
//-----------------------------------------------------------------------------------------------------------
/*
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gTERMINAL_PrintTitle
// DESCRIPTION: Prints Galcor terminal based GUI's title which appears on every screen
// ARGUMENTS: NONE
// INTERMEDIATE VARIABLES: NONE
// RETURN: NONE
// ERROR: NONE
// TESTED: YES / NO
*/
void gTERMINAL_PrintTitle( void )
{
    puts( "------------------------------------------------------------------------------" );
    puts( "***1.0***************************   GALCOR   ***************************1.0***" );
    puts( "------------------------------------------------------------------------------" );
    puts( "                      YOUR PERSONAL PROGRAMMING ASSISTANT                     " );
    printf( "\n" );
} // END FUNCTION gTERMINAL_PrintTitle
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gTERMINAL_PrintMenu
// DESCRIPTION:
// -- Prints the elements of the menuPtr <inMenu> and returns the user choice to the menu
// ARGUMENTS:
// -- inMenu        := Pointer to menu structure in which to print
// INTERMEDIATE VARIABLES:
// -- menuChoice    := The user's choice to the menu displayed by the function
// RETURN:
// -- < int > menuChoice
// ERROR: NONE
// TESTED: YES - LIMITED
*/
int gTERMINAL_PrintMenu( menuPtr *inMenu )
{
    int menuChoice = 0;

    if( inMenu->title != NULL ) { printf( "\t\t%22s MENU\n\n", inMenu->title ); }
    if( inMenu->opt1 != NULL ) { printf( "1.%s\n", inMenu->opt1 ); }
    if( inMenu->opt2 != NULL ) { printf( "2.%s\n", inMenu->opt2 ); }
    if( inMenu->opt3 != NULL ) { printf( "3.%s\n", inMenu->opt3 ); }
    if( inMenu->opt4 != NULL ) { printf( "4.%s\n", inMenu->opt4 ); }
    if( inMenu->opt5 != NULL ) { printf( "5.%s\n", inMenu->opt5 ); }
    if( inMenu->opt6 != NULL ) { printf( "6.%s\n", inMenu->opt6 ); }
    if( inMenu->opt7 != NULL ) { printf( "7.%s\n", inMenu->opt7 ); }
    if( inMenu->opt8 != NULL ) { printf( "8.%s\n", inMenu->opt8 ); }
    if( inMenu->opt9 != NULL ) { printf( "9.%s\n", inMenu->opt9 ); }

    printf( "0.EXIT\n\n---> " );
    scanf( "%d", &menuChoice );

    return menuChoice;
} // END FUNCTION gTERMINAL_PrintMenu
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gTERMINAL_InitializeMenu
// DESCRIPTION:
// -- Returns a pointer to a menu structure of a menu with the inputted characteristics
// -- All unused options should be inputted as NULL.
// ARGUMENTS:
// -- title             := Title of the menu to be created
// -- option( 0 -> 9 )  := Options of the menu to be created
// INTERMEDIATE VARIABLES:
// -- xMenu             := Pointer of type menuPtr which points to the created menu structure
// RETURN:
// -- xMenu
// ERROR: NONE
// TESTED: YES
*/
menuPtr *gTERMINAL_InitializeMenu( char title[ 20 ], char option1[ 20 ], char option2[ 20 ], char option3[ 20 ],
                                    char option4[ 20 ], char option5[ 20 ], char option6[ 20 ], char option7[ 20 ],
                                    char option8[ 20 ], char option9[ 20 ] )
{
	menuPtr *xMenu = malloc( sizeof( menu ) );
	xMenu->title = title;
	xMenu->opt1 = option1;
	xMenu->opt2 = option2;
	xMenu->opt3 = option3;
	xMenu->opt4 = option4;
	xMenu->opt5 = option5;
	xMenu->opt6 = option6;
	xMenu->opt7 = option7;
	xMenu->opt8 = option8;
	xMenu->opt9 = option9;
	return xMenu;
} // END FUNCTION gTERMINAL_InitializeMenu
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gTERMINAL_PrintIntegerArray
// DESCRIPTION:
// -- Prints an integer array at location pointed to by <source> which is <size> elements long.
// ARGUMENTS:
// -- source        := Pointer to address of first element in array which needs to be printed.
// -- size          := Size of the array to be printed.
// INTERMEDIATE VARIABLES:
// -- currentPtr    := Points to the current location of the element to be printed in the loop
// -- i             := Counter in for loop
// RETURN: NONE
// ERROR: NONE
// TESTED: YES - LIMITED
*/
void gTERMINAL_PrintIntegerArray( int *source, int size )
{
    gTERMINAL_PrintTitle();

	int *currentPtr = source;
	int i = 0;
	for ( i = 0; i < size; i++ )
    {
        printf( "Element %3d: %-5d\n", i, *currentPtr );
        currentPtr++;
    } // END for
} // END FUNCTION gTERMINAL_PrintIntegerArray
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: gTERMINAL_PrintFloatArray
// DESCRIPTION:
// -- Prints <size> elements of a floating-point array at location pointed to by <source>
// ARGUMENTS:
// -- source        := Pointer to address of first element in array which needs to be printed
// -- size          := Size of the array which needs to be printed
// INTERMEDIATE VARIABLES:
// -- currentPtr    := Points to the current location of the element to be printed in the loop
// -- i             := Counter in for loop
// RETURN: NONE
// ERROR: NONE
// TESTED: YES - LIMITED
*/
void gTERMINAL_PrintFloatArray( float *source, int size )
{
	gTERMINAL_PrintTitle();

	float *currentPtr = source;
	int i = 0;
	for( i = 0; i < size; i++ )
    {
        printf( "Element %3d: %-5f\n", i, *currentPtr );
        currentPtr++;
    }
} // END FUNCTION --
//-----------------------------------------------------------------------------------------------------------
