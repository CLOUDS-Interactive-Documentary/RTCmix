/*
 *	mixerr.h: for MIX11 error codes
 */
#pragma once

#define	MX_NOERR	0
#define MX_FEXIST	1
#define	MX_FNAME	2
#define	MX_EMEM		3
#define	MX_FAIL		4

#define	MX_NERR		5	/*  Number of standard error codes	*/

static int mixerr;
//int mixerr;
extern	char *mix_errlist[];
