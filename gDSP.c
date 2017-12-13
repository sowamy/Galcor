//-----------------------------------------------------------------------------------------------------------
/* FILE: gDSP.c
 * DESCRIPTION: This file contains functionality and data structures which describes
 * 				and processes digital signals in a multitude of environments.
 */
//-----------------------------------------------------------------------------------------------------------
/* STRUCTURE: PeriodicSignal
 * DESCRIPTION:
 * -- This structure contains a periodic digital signal and it's attributes.
 * MATHEMATICAL EQUATIONS:
 * -- x(n + d) = A cos(wn + p), a < n < b
 * -- -- x(n)	:= The amplitude of the signal at sample number n.
 * -- -- n		:= The sample number.
 * -- -- d		:= The amount of samples the signal is delayed from time 0.
 * -- -- A		:= The (max) amplitude of the periodic signal.
 * -- -- w		:= The frequency of the signal in radians per second.
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
}; // END STRUCTURE --
//-----------------------------------------------------------------------------------------------------------
