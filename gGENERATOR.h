#ifndef GGENERATOR_H
#define GGENERATOR_H
int *gGENERATOR_DCSignalGenerator0( int size, int amplitude, int delay );
double *gGENERATOR_DCSignalGenerator1( int size, double amplitude, int delay );
int *gGENERATOR_DCSignalInserter0( int *signalSource, int index, int sourceSize, int amplitude, int signalSize );
double *gGENERATOR_DCSignalInserter1( double *signalSource, int index, int sourceSize, double amplitude, int signalSize );
int *gGENERATOR_ImpulseSignalGenerator0( int size, int amplitude, int delay );
double *gGENERATOR_ImpulseSignalGenerator1( int size, double amplitude, int delay );
int *gGENERATOR_RandomIntegerSignalGenerator( int size, int minRange, int maxRange );\
#endif // GGENERATOR_H

