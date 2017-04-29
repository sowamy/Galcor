#ifndef GDSP_H
#define GDSP_H
int *gDSP_DCSignalGenerator0( int size, int amplitude, int delay );
float *gDSP_DCSignalGenerator1( int size, float amplitude, int delay );
int *gDSP_DCSignalInserter0( int *signalSource, int index, int sourceSize, int amplitude, int signalSize );
float *gDSP_DCSignalInserter1( float *signalSource, int index, int sourceSize, float amplitude, int signalSize );
int *gDSP_ImpulseSignalGenerator0( int size, int amplitude, int delay );
float *gDSP_ImpulseSignalGenerator1( int size, float amplitude, int delay );
int *gDSP_RandomIntegerSignalGenerator( int size, int minRange, int maxRange );
#endif // GDSP_H

