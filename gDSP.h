#ifndef GDSP_H
#define GDSP_H
float *gDSP_DCSignalGenerator( size_t size, float amplitude, int delay );
float *gDSP_ImpulseSignalGenerator( int size, float amplitude, int delay );
int *gDSP_RandomIntegerSignalGenerator( int size, int minRange, int maxRange );
#endif // GDSP_H
