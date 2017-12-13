#ifndef GDSP_H
#define GDSP_H

#define PI 3.14159265359

struct PeriodicSignal {
	int delay;
	int n;
	int samplingTime;
	double *signal;
	double amplitude;
	double frequency_radPerSample;
	double frequency_cyclesPerSample;
	double phase; // In radians
}; // END STRUCTURE PeriodicSignal

typedef struct PeriodicSignal *PeriodicSignalPtr;

PeriodicSignalPtr periodicSignalGenerator(int n, int delay, double amplitude, double phase, double freq);
double signalEnergy (double *signal, int a, int b);

#endif // GDSP_H
