//-----------------------------------------------------------------------------------------------------------
/* FILE: gDSP.c
 * DESCRIPTION: This file contains functionality and data structures which describes
 * 				and processes digital signals in a multitude of environments.
 */
//-----------------------------------------------------------------------------------------------------------
// Included Libraries
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//-----------------------------------------------------------------------------------------------------------
// Constants
#define PI 3.14159265359
//-----------------------------------------------------------------------------------------------------------
// Structure and Type Definitions
/* STRUCTURE: PeriodicSignal
 * DESCRIPTION:
 * -- This structure contains the samples and characteristics of a non-periodic signal
 * -- NOTE: I have decided to not use structures as a standard i/o interaction between the program and
 			the user. I feel this decision allows the program to be more flexible to the user's needs,
			and doesn't require the user to implement 'extra' functionality to interact with the program.
 * -- NOTE: There are some functions in this program which require and return a variety of variables, in which
 			then the user should initialize and define these structures as needed.
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
	double totalEnergy;
	double totalPower;
}; // END STRUCTURE Signal
typedef struct Signal *SignalPtr;
//-----------------------------------------------------------------------------------------------------------
// Structure and Type Definitions
/* STRUCTURE: PeriodicSignal
 * DESCRIPTION:
 * -- This structure contains a periodic digital signal and it's attributes.
 * -- NOTE: I have decided to not use structures as a standard i/o interaction between the program and
		   the user. I feel this decision allows the program to be more flexible to the user's needs,
		   and doesn't require the user to implement 'extra' functionality to interact with the program.
 * -- NOTE: There are some functions in this program which require and return a variety of variables, in which
		   then the user should initialize and define these structures as needed.
 * MATHEMATICAL EQUATIONS:
 * -- General Formula of a Digital Periodic Sinusoidal Signal
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
// Function Prototypes
PeriodicSignalPtr periodicSignalGenerator (int n, int delay, double amplitude, double phase, double freq);
SignalPtr getSignalAttributes (double* sigInc, int n);
double signalEnergy (double *signal, int a, int b);
double signalPower (double *sigInc, int a, int b);
double* scaleSignal (double* sigInc, int n, double scaler);
double* sumSignals (double* sig1, double* sig2, int a, int b);
double* multiplySignals (double* sig1, double* sig2, int a, int b);
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: getSignalAttributes
 * DESCRIPTION:
 * -- Given a signal <sigInc> and the number of samples it contains <n>; this function returns
 *		a variety of characteristics of the signal inputted. This function returns a signal structures
 *		which contains a variety of information about the signal.
 * ARGUMENTS:
 * -- sigInc	:= Inputted signal to be evaluated
 * -- n			:= Number of samples in the signal
 * INTERMEDIATE VARIABLES:
 * -- delayFlag	:= Used to find the delay of the signal
 * RETURN:
 * -- ss		:= Stores the newly created <Signal> structure
 * ERROR:
 * -- NONE
 * TESTED: YES - limited
 */
SignalPtr getSignalAttributes (double* sigInc, int n)
{
	int i = 0;	// counter
	bool delayFlag = true;

	// Allocates memory needed for <Signal> structure
	SignalPtr ss = (SignalPtr)malloc(sizeof(struct Signal));
	ss->signal = (double*)malloc(sizeof(double)*n);

	// Initializes attributes of the signal
	ss->signal = sigInc;
	ss->delay = 0;
	ss->maxAmplitude_pos = *sigInc;
	ss->maxAmplitude_neg = *sigInc;
	ss->totalEnergy = signalEnergy(sigInc, 0, n);
	ss->totalPower = signalPower(sigInc, 0, n);

	// Iterates through entire signal, getting characterics along the way
	for(i = 0; i < n; i++) {
		// Incrementes delay value for every 0 at the beginning of the signal
		if(delayFlag == true && *sigInc == 0) {
			ss->delay++;
		} else {
			delayFlag = false;
		} // END IF...ELSE : Delay

		// Redefines the maximum and minimum amplitudes of the signal if the next sample is
		// 	greater or less than the current maximum and minimum
		if( *sigInc > ss->maxAmplitude_pos ){ ss->maxAmplitude_pos = *sigInc; }
		if( *sigInc < ss->maxAmplitude_neg ){ ss->maxAmplitude_neg = *sigInc; }

		sigInc++;
	} // END FOR : Iterates through entire signal

	return ss;
} // END FUNCTION getSignalAttributes
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
 * ERRORS:
 * -- NONE
 * TESTED: YES - limited
 */
PeriodicSignalPtr periodicSignalGenerator(int n, int delay, double amplitude, double phase, double freq)
{
	// Counters
	int i = 0;
	int j = 0;

	// Pointers
	double *sigBase = (double *)malloc( sizeof(double)*n );
	double *sample = sigBase;

	double w = freq * 2 * PI;
	double x = 0;

	// Delay the signal
	while(i < delay) {
		*sample = 0.0;
		sample++;
		i++;
	} // END WHILE : Delay

	// Create the periodic sinusoid
	while(j < (n-delay)) {
		x = amplitude * cos( w*((double)j+(double)delay) + phase );
		*sample++ = x;
		j++;
	} // END WHILE : Signal Creation

	// Initialize and pass signal structure
	PeriodicSignalPtr sigStruct = (PeriodicSignalPtr)malloc(sizeof(struct PeriodicSignal));
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
 * -- sigInc	:= Pointer to the first address of the signal to be evaluated.
 * -- a			:= Sample to start calculating the energy.
 * -- b			:= Final sample to calculate the energy.
 * RETURN:
 * -- energy	:= Calculated energy of the signal.
 * ERRORS:
 * -- Logic Error: Yields incorrect results if b > a
 * -- Compile Error: This function causes a terminal type error if a and b are not integers, and
 						sigInc is not double*
 * TESTED: YES
 */
double signalEnergy (double *sigInc, int a, int b)
{
	int i = 0;
	double energy = 0;

	if(a != 0){ for(i = 0;i < a;i++) { sigInc++; } }

	for(i = 0;i <= (b-a);i++) {
		energy += *sigInc * *sigInc;
		sigInc++;
	} // END FOR

	return energy;
} // END FUNCTION signalEnergy
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: signalEnergy
 * DESCRIPTION:
 * -- Takes in a pointer to the first address of a <signal>, the sample to start taking the energy <a>,
 *		and the last sample to take the energy. Then return the <power> calculated between the two
 *		samples given of the inputted signal.
 * MATHEMATICAL EQUATIONS:
 * -- P = x(n)^2 / N , a < n < b
 * -- N = b - a
 * -- -- P	:= Power of the signal
 * -- -- x	:= The magnitude of the signal at sample n
 * -- -- n	:= Signal sample
 * -- -- N	:= Total number of samples of which the signal consists
 * -- -- a	:= First signal to start taking the energy
 * -- -- b	:= Final signal to calculate the energy of
 * ARGUMENTS:
 * -- sigInc	:= Pointer to the first address of the signal to be evaluated.
 * -- a			:= Sample to start calculating the energy.
 * -- b			:= Final sample to calculate the energy.
 * ERRORS:
 * -- Logic Error: Yields incorrect results if b > a
 * -- Logic Error: Yields incorrect results if a and b are not in the range of the inputted signal.
 *					N is incorrectly evaluated, making the power fractionally less as the range is increased.
 * -- Compile Error: This function causes a terminal type error if a and b are not integers, and sigInc is not double*
 * TESTED: YES
 */
double signalPower (double *sigInc, int a, int b) { return signalEnergy(sigInc, a, b) / ((b - a)); }
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: scale
 * DESCRIPTION:
 * -- Scales the amplitude of the inputted signal <sigInc> with <n> sample by the inputted <scaler>.
 * -- Returns the scaled signal <ss> which will be of the same length as in inputted signal <sigInc>.
 * MATHEMATICAL EQUATIONS:
 * -- y(n) = Ax(n)
 * -- -- y	:= Scaled signal
 * -- -- x	:= Original signal
 * -- -- A	:= Amount that the original signal is to be scaled
 * ARGUMENTS:
 * -- sigInc	:= Original signal to be scaled
 * -- n			:= Number of samples of the original signal
 * -- scaler	:= Amount that the outputted signal is to be scaled
 * INTERMEDIATE VARIABLES:
 * -- ssInc		:= Pointer to be incremented, used to assign values to ss.
 * RETURN:
 * -- ss		:= Scaled signal returned
 * ERRORS:
 * -- Compile Error: This function causes a terminal error if the types do not match the arguments
 						as specified in the function prototype
 * TESTED: YES - limited
 */
double* scaleSignal (double* sigInc, int n, double scaler)
{
	int i = 0;	// counter
	double* ss = (double*) malloc(sizeof(double)*n);
	double* ssInc = ss;

	while(i < n) {
		*ssInc = scaler * *sigInc;
		ssInc++;
		sigInc++;
		i++;
	} // END WHILE : Scaling

	return ss;
} // END FUNCTION scaleSignal
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: sumSignals
 * DESCRIPTION:
 * -- Adds 2 signals <sig1> and <sig2> from starting sample <a> to the final sample <b>.
 * -- Returns the summed signal <y> which is of the length <n>.
 * -- NOTE: I have decided to leave it up to the user to figure the number of samples in summed signal <y>.
 			This can be easily done by subtracting the final argument <b> from the third <a>.
 * -- NOTE: I have decided to leave it up to the user to parse the ranges of each signal inputted to avoid
 			this function being overcomplicated and the errors which might result. This can be done using
			a signal translation function in combination with this one. It is suggestible to allow
			the user to insert custom ranges of each inputted signal if this function is to be
			employed in a programming language which features a standard error handling library.
 * MATHEMATICAL EQUATIONS:
 * -- y(n) = x1(n) + x2(n)
 * -- -- n	:= Particular sample number
 * -- -- x1	:= First signal to be summed	(addend)
 * -- -- x2 := Second signal to be summed	(addend)
 * -- -- y	:= Sum of the two signals
 * ARGUMENTS:
 * -- sig1	:= Pointer to first signal to be summed
 * -- sig2	:= Pointer to second signal to be summed
 * -- a		:= Starting sample of which both signals are to be summed
 * -- b		:= Final sample of which both signal are to be summed
 * INTERMEDIATE VARIABLES:
 * -- yInc	:= Pointer to the summed signal which is incremented and used to assign the summations
 * RETURN:
 * -- y		:= The pointer to the summed signal
 * ERRORS:
 * -- Logic Error: If the ranges <a> and <b> are outside of either <sig1> or <sig2> ranges, this function will
 					yield incorrect results.
 * -- Runtime Error: This function causes a terminal error known as a segmentation fault if the value for
 					integer <b> is smaller than the value for integer <a>.
 * -- Compile Error: This function will cause a terminal type error if the types of the arguments are not the
 					same as specified in the function prototype.
 * TESTED: YES - limited
 */
double* sumSignals (double* sig1, double* sig2, int a, int b)
{
	// Counters
	int i = 0;
	int j = 0;

	double* y = (double*)malloc(sizeof(double)*(b - a));
	double* yInc = y;

	// Increment each signal pointer to the starting sample
	while(i < a) {
		sig1++;
		sig2++;
		i++;
	} // END WHILE : Starting Sample

	// Sum both signals <sig1> and <sig2> together into signal <y>
	while(j < (b - a)) {
		*yInc = *sig1 + *sig2;
		yInc++;
		sig1++;
		sig2++;
		j++;
	} // END WHILE :

	return y;
} // END FUNCTION sumSignals
//-----------------------------------------------------------------------------------------------------------
/* FUNCTION: multiplySignals
 * DESCRIPTION:
 * -- Multiplies 2 signals <sig1> and <sig2> from starting sample <a> to the final sample <b>.
 * -- Returns the resulting signal <y> which is of the length <n>.
 * -- NOTE: I have decided to leave it up to the user to figure the number of samples in resulting signal <y>.
 			This can be easily done by subtracting the final argument <b> from the third <a>.
 * -- NOTE: I have decided to leave it up to the user to parse the ranges of each signal inputted to avoid
 			this function being overcomplicated and the errors which might result. This can be done using
			a signal translation function in combination with this one. It is suggestible to allow
			the user to insert custom ranges of each inputted signal if this function is to be
			employed in a programming language which features a standard error handling library.
 * MATHEMATICAL EQUATIONS:
 * -- y(n) = x1(n) * x2(n)
 * -- -- n	:= Particular sample number
 * -- -- x1	:= First signal to be summed	(multiplicand)
 * -- -- x2 := Second signal to be summed	(multiplier)
 * -- -- y	:= Resulting signal				(product)
 * ARGUMENTS:
 * -- sig1	:= Pointer to the multiplicand
 * -- sig2	:= Pointer to the multiplier
 * -- a		:= Starting sample of which both signals are to be multiplied
 * -- b		:= Final sample of which both signal are to be multiplied
 * INTERMEDIATE VARIABLES:
 * -- yInc	:= Pointer to the product signal which is incremented and used to assign the products each sample
 * RETURN:
 * -- y		:= The pointer product signal
 * ERRORS:
 * -- Logic Error: If the ranges <a> and <b> are outside of either <sig1> or <sig2> ranges, this function will
 					yield incorrect results.
 * -- Runtime Error: This function causes a terminal error known as a segmentation fault if the value for
 					integer <b> is smaller than the value for integer <a>.
 * -- Compile Error: This function will cause a terminal type error if the types of the arguments are not the
 					same as specified in the function prototype.
 * TESTED: YES - limited
 */
double* multiplySignals (double* sig1, double* sig2, int a, int b)
{
	// Counters
	int i = 0;
	int j = 0;

	double* y = (double*)malloc(sizeof(double)*(b - a));
	double* yInc = y;

	// Increment each signal pointer to the starting sample
	while(i < a) {
		sig1++;
		sig2++;
		i++;
	} // END WHILE : Starting Sample

	// Sum both signals <sig1> and <sig2> together into signal <y>
	while(j < (b - a)) {
		*yInc = *sig1 * *sig2;
		yInc++;
		sig1++;
		sig2++;
		j++;
	} // END WHILE :

	return y;
} // END FUNCTION sumSignals
//-----------------------------------------------------------------------------------------------------------
