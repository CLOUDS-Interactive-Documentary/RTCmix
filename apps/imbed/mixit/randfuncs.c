#include <math.h>
#include <sys/time.h>

static  long    randx = 1;


/* srrand() seeds the rrand() and brrand() random number generators */

void srrand(unsigned x)
{
	randx = x;
}


/* rrand() -- modification of unix rand() to return floating point values 
   between + and - 1.0 */

float rrand()
{
	int i = ((randx = randx*1103515245 + 12345)>>16) & 077777;
	return((float)i/16384. - 1.);
}


/* brrand() -- a modification of unix rand() to return floating point values
   between 0.0 and 1..0 */

float brrand()
{
	int i = ((randx = randx*1103515245 + 12345)>>16) & 077777;
	return((float)i/32768.0);
}


/* tsrand() seeds srrand() and brrand() with time of day */

void tsrand()
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv,&tz);
	srrand(tv.tv_usec);
}


/* gaussian - gaussian random distribution with fixed boundaries (0-1)
   (by luke) */

float gaussian()
{
	int j;
	int N = 12; /* number of passes for the gaussian curve */
	int halfN = 6;
	int scale = 1;
	float output;
	float sigma = .166666;
	float mu = .5;
	float randnum;

	randnum = 0.0;
	for(j = 0; j < N; j++) {
		randnum += brrand();
  	}

	output = -1.0;
	while ( (output < 0.0) && (output > 1.0) ) {
		output = sigma*scale*(randnum-halfN)+mu;
	}

	return(output);
}


/* cauchy - cauchy random distribution with fixed boundaries (0-1)
   (by luke) */


float cauchy()
{
	float alpha = .00628338;
	float pi = 3.1415927;
	float output;
	float randnum;

	output = -1.0;
	while ( (output < 0.0) && (output > 1.0) ) {
		randnum = brrand();
		randnum *= pi;

		output=(alpha*tan(randnum))+0.5;
	}

	return(output);
}


/* linlo() - lower -limit weighted random numbers
   (by luke) */

float linlo()
{
	float randnum, randnum2;

	randnum = brrand();
	randnum2 = brrand();
	if(randnum2 < randnum) randnum = randnum2;

	return(randnum);
}


/* linhi() - upper-limit weighted random numbers
   (by luke) */

float linhi()
{
	float randnum, randnum2;

	randnum = brrand();
	randnum2 = brrand();
	if(randnum2 > randnum) randnum = randnum2;

	return(randnum);
}


/* triangle -- triangle-curve of  random numbers between 0 and 1
   (by luke) */

float triangle()
{
	float randnum, randnum2, output;

	randnum = brrand();
	randnum2 = brrand();
	output = 0.5*(randnum+randnum2);

	return(output);
}

