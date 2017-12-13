//-----------------------------------------------------------------------------------------------------------
/* FILE: gDSP.c
 * DESCRIPTION: This file contains functionality and data structures which describes
 * 				and processes digital signals in a multitude of environments.
 */
//-----------------------------------------------------------------------------------------------------------
// Included Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//-----------------------------------------------------------------------------------------------------------
// Constants
#define PI 3.14159265359
//-----------------------------------------------------------------------------------------------------------
// Structure and Type Definitions
/* STRUCTURE: PeriodicSignal
 * DESCRIPTION:
 * -- This structure contains the samples and characteristics of a non-periodic signal
 * VARIABLES:
 * -- delay 					:= The number of samples that the signal is delayed from time 0.
 * -- n 						:= The number of samples of which the signal consists.
 * -- samplingTime 				:= The amount of time in microseconds between each sample.
 * -- signal 					:= A pointer to the address of the first sample in the signal.
 *									This pointer may be incremented to obtain each individual sample of the signal.
 * -- amplitude_pos 			:= Describes the highest magnitude of a sample in the signal.
 * -- amplitude_neg				:= Describes the lowest magnitude of a sample in the signal.
 */
struct Signal {
	int delay;
	int n;
	int samplingTime;
	double *signal;
	double maxAmplitude_pos;
	double maxAmplitude_neg;
}; // END STRUCTURE Signal
typedef struct Signal *SignalPtr;
//-----------------------------------------------------------------------------------------------------------
// Structure and Type Definitions
/* STRUCTURE: PeriodicSignal
 * DESCRIPTION:
 * -- This structure contains a periodic digital signal and it's attributes.
 * MATHEMATICAL EQUATIONS:
 * -- General Formula of a Digita Periodic Sinusoidal Signal
 * -- x(n + d) = A cos(wn + p), a < n < b
 * -- -- x(n)	:= The amplitude of the signal at sample number n.
 * -- -- n		:= The sample number.
 * -- -- d		:= The amount of samples the signal is delayed from time 0.
 * -- -- A		:= The (max) amplitude of the periodic signal.
 * -- -- w		:= The frequency of the signal in radians per sample.
 * -- -- p		:= The phase shift of the signal in radians.
 * -- -- a		:= The first sample in which the signal is described.
 * -- -- b		:= The last sample in which the sample is described.
 * VARIABLES:
 * -- delay 					:= The number of samples that the signal is delayed from time 0.
 * -- n 						:= The number of samples of which the signal consists.
 * -- samplingTime 				:= The amount of time in microseconds between each sample.
 * -- signal 					:= A pointer to the address of the first sample in the signal.
 *									This pointer may be incremented to obtain each individual sample of the signal.
 * -- amplitude 				:= Describes the highest and lowest samples in the signal.
 * -- frequency_radPerSample	:= The frequency of the signal in radians per second.
 * -- frequency_cyclesPerSample := The number of cycles of the signal per sample.
 * -- phase						:= The phase shift of the signal in radians.
 */
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
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: periodicSignalGenerator
 * DESCRIPTION:
 * -- Takes in the <amplitude>, number of samples <n>, the frequency in cycles per sample <freq>, the
 *		phase shift <phase>,and the <delay>. Returns a pointer to a <PeriodicSignal>. The newly created
 *		structure will contain all of the characteristics of a digital signal.
 * MATHEMATICAL EQUATIONS:
 * -- General Formula of a Digita Periodic Sinusoidal Signal
 * -- x(n + d) = A cos(wn + p), a < n < b
 * -- -- x(n)	:= The amplitude of the signal at sample number n.
 * -- -- n		:= The sample number.
 * -- -- d		:= The amount of samples the signal is delayed from time 0.
 * -- -- A		:= The (max) amplitude of the periodic signal.
 * -- -- w		:= The frequency of the signal in radians per sample.
 * -- -- p		:= The phase shift of the signal in radians.
 * -- -- a		:= The first sample in which the signal is described.
 * -- -- b		:= The last sample in which the sample is described.
 * -- Find the Frequency <w> (Radians per Sample), Given the Frequency <f> (Cycles per Second).
 * -- w = 2*PI*f
 * -- -- w		:= The frequency of the signal in radians per sample.
 * -- -- f		:= The frequency of the signal in cycles per sample.
 * ARGUMENTS:
 * -- n				:= The total number of samples the completed signal is to contain.
 * -- delay			:= The number of samples the signal is delayed.
 * -- amplitude		:= The amplitude of the signal.
 * -- phase			:= The phase shift of the signal in radians.
 * -- freq			:= The frequency of the signal in cycles per sample.
 * INTERMEDIATE VARIABLES:
 * -- w				:= The frequency of the signal in radians per sample.
 * -- sigBase		:= Pointer to the first address in the created signal.
 * -- sample		:= Pointer which is incremented throughout the function, used to create the signal.
 * RETURN:
 * -- sigStruct		:= Pointer to the structure which contains the signal and all its information.
 * ERROR:
 * -- NONE
 * TESTED: NO
 */
PeriodicSignalPtr periodicSignalGenerator(int n, int delay, double amplitude, double phase, double freq)
{
	// Counters
	int i = 0;
	int j = 0;

	// Pointers
	double *sigBase = malloc( sizeof(double)*n );
	double *sample = sigBase;

	double w = freq * 2 * PI;
	double x = 0;

	// Delay the signal
	for(i; i < delay; i++) {
		*sample = 0.0;
		sample++;
	} // END FOR : Delay

	// Create the periodic sinusoid
	for(j; j < (n-delay); j++) {
		x = amplitude * cos( w*((double)j+(double)delay) + phase );
		*sample++ = x;
	} // END FOR : Signal Creation

	// Initialize and pass signal structure
	PeriodicSignalPtr sigStruct = malloc(sizeof(struct PeriodicSignal));
	sigStruct->amplitude = amplitude;
	sigStruct->delay = delay;
	sigStruct->frequency_cyclesPerSample = freq;
	sigStruct->frequency_radPerSample = w;
	sigStruct->n = n;
	sigStruct->signal = sigBase;

	free(sigBase);

	return sigStruct;

} // END FUNCTION periodicSignalGenerator
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: signalEnergy
 * DESCRIPTION:
 * -- Takes in a pointer to the first address of a <signal>, the sample to start taking the energy <a>,
 *		and the last sample to take the energy. Then return the <energy> calculated between the two
 *		samples given of the inputted signal.
 * MATHEMATICAL EQUATIONS:
 * -- E = x(n)^2, a < n < b
 * -- -- E	:= Energy of the signal
 * -- -- x	:= The magnitude of the signal at sample n
 * -- -- n	:= Signal sample.
 * -- -- a	:= First signal to start taking the energy.
 * -- -- b	:= Final signal to calculate the energy of.
 * ARGUMENTS:
 * -- signal	:= Pointer to the first address of the signal to be evauluated.
 * -- a			:= Sample to start calculating the energy.
 * -- b			:= Final sample to calculate the energy.
 * INTERMEDIATE VARIABLES:
 * -- <variables not returned or in arguments> := <description>
 * RETURN:
 * -- energy	:= Calculated energy of the signal.
 * ERROR:
 * --  NONE
 * TESTED: NO
 */
double signalEnergy (double *sigInc, int a, int b)
{
	int i = 0;
	double energy = 0;

	for(i = 0;i < a;i++) { sigInc++; };

	for(i = 0;i < (b-a);i++) {
		energy += *sigInc * *sigInc;
		sigInc++;
	} // END FOR

	return energy;
} // END FUNCTION signalEnergy
//-----------------------------------------------------------------------------------------------------------
