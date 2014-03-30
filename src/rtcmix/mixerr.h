/*
 *	mixerr.h: for MIX11 error codes
 */

#define	MX_NOERR	0
#define MX_FEXIST	1
#define	MX_FNAME	2
#define	MX_EMEM		3
#define	MX_FAIL		4

#define	MX_NERR		5	/*  Number of standard error codes	*/

#ifdef WIN32
int mixerr;
#else
extern	int mixerr;
#endif
extern	char *mix_errlist[];
