# Galcor 
## Version: 0.2

## Introduction
### Audience
Galcor's intended audience are fellow programmers who find themselves continuously writing what seems like the code which does the same things repeatively; and therefore, have the desire to reduce effort and time programming.
### Purpose 
Galcor reduces programming time and effort by presenting programmers with a multitude of libraries, which contain functionality aimed to solve common problems in programming and engineering.

## Body
Galcor contains a variety of C programs and their header files, each created and used of a set of intended purposes. The main.c file in Galcor is currently used for testing purposes only. Galcor is a library to be implemented in other programs, not a program within it's own right.

### Usage
To use Galcor appropriately, the user must include the header to the desired library.

Example: __#include "./home/Desktop/Galcor/galcor.h"__

The user then should be able to access any and all functionality featured within the corresponding C file.

## Libraries

### galcor
#### Theory
Galcor's core module (galcor.c) is used to implement general functionality and structures used in programming. 

### gGENERATOR
#### Theory
gGENERATOR is used to generate an array of values of a specified type and behavior.

### gTERMINAL
#### Theory
gTERMINAL is used to display arrays and strings to a terminal.

### gDSP
#### Theory
gDSP is used to perform a series of Digital Signal Processing operations on arrays of type double arrays. 

### gECON
#### Theory
gECON is used to perform a variety of financial operations.

### gTEST
#### Theory
gTEST is used to provide the user with the functionality to test a particular function's ability to handle a variety of input, and time the functions abiltiy to operate in both favoriable and unfavoriable conditions.

### gERROR
#### Theory
gERROR is used to provide the user with the ability to quickly throw and handle errors given a set of conditions.
