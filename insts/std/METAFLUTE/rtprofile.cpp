#ifndef OF_ANDROID

#include <rt.h>

void
rtprofile()
{
	RT_INTRO("SFLUTE",makeSFLUTE);
	RT_INTRO("BSFLUTE",makeBSFLUTE);
	RT_INTRO("VSFLUTE",makeVSFLUTE);
	RT_INTRO("LSFLUTE",makeLSFLUTE);
}

#endif // OF_ANDROID

