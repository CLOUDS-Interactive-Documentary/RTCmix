/* RTcmix - Copyright (C) 2004  The RTcmix Development Team
   See ``AUTHORS'' for a list of contributors. See ``LICENSE'' for
   the license to this software and for a DISCLAIMER OF ALL WARRANTIES.
*/
#include <Orand.h>
#ifdef _MSC_VER
#include <time.h>
#include <times.h>
#else
#include <sys/time.h>
#endif

Orand::Orand() : rand_x(1)
{
}

Orand::Orand(int seed) : rand_x(seed)
{
}

void Orand::seed(int seed)
{
	rand_x = seed;
}

void Orand::timeseed()
{
	struct timeval tv;
#ifdef _MSC_VER
	int tz;
#else
	struct timezone tz;
#endif
	gettimeofday(&tv,&tz);
	seed(tv.tv_usec);
}

float Orand::random()
{
	long i = ((rand_x = rand_x * 1103515245 + 12345) >> 16) & 077777;
	return (float) i / 32768.0;
}

float Orand::rand()
{
	long i = ((rand_x = rand_x * 1103515245 + 12345) >> 16) & 077777;
	return ((float) i / 16384.0) - 1.0;
}

float Orand::range(float min, float max)
{
	return min + (random() * (max - min));
}

