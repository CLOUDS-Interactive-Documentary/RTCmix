/*

        Copyright (C) 1999 Juhana Sadeharju
                       kouhia at nic.funet.fi

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    */

#ifndef GVERB_H
#define GVERB_H

// BGG from c74/max/ext_common.h
#define CLIP(a, lo, hi) ( (a)>(lo)?( (a)<(hi)?(a):(hi) ):(lo) )


#include <math.h>
#include <string.h>
#include <stdio.h>

#define FDNORDER 4

typedef struct
{
	int bypass;
	int rate;
	float inputbandwidth;
	float drylevel;
	float taillevel;
	float earlylevel;
	ty_damper *inputdamper;
	float maxroomsize;
	float roomsize;
	float revtime;
	float maxdelay;
	float largestdelay;
	ty_fixeddelay **fdndels;
	float *fdngains;
	int *fdnlens;
	ty_damper **fdndamps; 
	float fdndamping;
	ty_diffuser **ldifs;
	ty_diffuser **rdifs;
	ty_fixeddelay *tapdelay;
	int *taps;
	float *tapgains;
	float *d;
	float *u;
	float *f;
	double alpha;
} ty_gverb;


static void gverb_do(ty_gverb *, float, float *, float *);
static void gverb_set_roomsize(ty_gverb *, double);
static void gverb_set_revtime(ty_gverb *, double);
static void gverb_set_damping(ty_gverb *, double);
static void gverb_set_inputbandwidth(ty_gverb *, double);
static void gverb_set_drylevel(ty_gverb *, double);
static void gverb_set_earlylevel(ty_gverb *, double);
static void gverb_set_taillevel(ty_gverb *, double);

/*
 * This FDN reverb can be made smoother by setting matrix elements at the
 * diagonal and near of it to zero or nearly zero. By setting diagonals to zero
 * means we remove the effect of the parallel comb structure from the
 * reverberation.  A comb generates uniform impulse stream to the reverberation
 * impulse response, and thus it is not good. By setting near diagonal elements
 * to zero means we remove delay sequences having consequtive delays of the
 * similar lenths, when the delays are in sorted in length with respect to
 * matrix element index. The matrix described here could be generated by
 * differencing Rocchesso's circulant matrix at max diffuse value and at low
 * diffuse value (approaching parallel combs).
 *
 * Example 1:
 * Set a(k,k), for all k, equal to 0.
 *
 * Example 2:
 * Set a(k,k), a(k,k-1) and a(k,k+1) equal to 0.
 *
 * Example 3: The transition to zero gains could be smooth as well.
 * a(k,k-1) and a(k,k+1) could be 0.3, and a(k,k-2) and a(k,k+2) could
 * be 0.5, say.
 */

static inline void gverb_fdnmatrix(float *a, float *b)
{
  const float dl0 = a[0], dl1 = a[1], dl2 = a[2], dl3 = a[3];

  b[0] = 0.5f*(+dl0 + dl1 - dl2 - dl3);
  b[1] = 0.5f*(+dl0 - dl1 - dl2 + dl3);
  b[2] = 0.5f*(-dl0 + dl1 - dl2 + dl3);
  b[3] = 0.5f*(+dl0 + dl1 + dl2 + dl3);
}

static inline void gverb_do(ty_gverb *p, float x, float *yl, float *yr)
{
	float z;
	unsigned int i;
	float lsum,rsum,sum,sign;

	if(IS_NAN_FLOAT(x) || IS_DENORM_FLOAT(x) || fabsf(x) > 100000.0f)
	{
		x = 0.0f;
	}

	z = damper_do(p->inputdamper, x);

	z = diffuser_do(p->ldifs[0],z);

	for(i = 0; i < FDNORDER; i++)
	{
		p->u[i] = p->tapgains[i]*fixeddelay_read(p->tapdelay,p->taps[i]);
	}
	fixeddelay_write(p->tapdelay,z);

	for(i = 0; i < FDNORDER; i++)
	{
		p->d[i] = damper_do(p->fdndamps[i],
							p->fdngains[i]*fixeddelay_read(p->fdndels[i],
							p->fdnlens[i]));
	}

	sum = 0.0f;
	sign = 1.0f;
	for(i = 0; i < FDNORDER; i++)
	{
		sum += sign*(p->taillevel*p->d[i] + p->earlylevel*p->u[i]);
		sign = -sign;
	}
	sum += x*p->earlylevel;
	lsum = sum;
	rsum = sum;

	gverb_fdnmatrix(p->d,p->f);

	for(i = 0; i < FDNORDER; i++)
	{
		fixeddelay_write(p->fdndels[i],p->u[i]+p->f[i]);
	}

	lsum = diffuser_do(p->ldifs[1],lsum);
	lsum = diffuser_do(p->ldifs[2],lsum);
	lsum = diffuser_do(p->ldifs[3],lsum);
	rsum = diffuser_do(p->rdifs[1],rsum);
	rsum = diffuser_do(p->rdifs[2],rsum);
	rsum = diffuser_do(p->rdifs[3],rsum);

	*yl = lsum;
	*yr = rsum;
}

static inline void gverb_set_roomsize(ty_gverb *p, double a)
{
	unsigned int i;

	if(a <= 1.0 || IS_NAN_FLOAT(a))
	{
		p->roomsize = 1.0;
	}
	else
	{
		p->roomsize = CLIP(a, 1.0f, p->maxroomsize);
	}
	p->largestdelay = p->rate * p->roomsize * 0.00294f;

	p->fdnlens[0] = ff_round(1.000000f*p->largestdelay);
	p->fdnlens[1] = ff_round(0.816490f*p->largestdelay);
	p->fdnlens[2] = ff_round(0.707100f*p->largestdelay);
	p->fdnlens[3] = ff_round(0.632450f*p->largestdelay);
	for(i = 0; i < FDNORDER; i++)
	{
		p->fdngains[i] = -powf((float)p->alpha, p->fdnlens[i]);
	}

	p->taps[0] = 5+ff_round(0.410f*p->largestdelay);
	p->taps[1] = 5+ff_round(0.300f*p->largestdelay);
	p->taps[2] = 5+ff_round(0.155f*p->largestdelay);
	p->taps[3] = 5+ff_round(0.000f*p->largestdelay);

	for(i = 0; i < FDNORDER; i++)
	{
		p->tapgains[i] = powf((float)p->alpha, p->taps[i]);
	}
}

static inline void gverb_set_revtime(ty_gverb *p, double a)
{
	float ga,gt;
	double n;
	unsigned int i;

	p->revtime = CLIP(a, 0.1f, 360.0f);

	ga = 60.0f;
	gt = p->revtime;
	ga = powf(10.0f,-ga/20.0f);
	n = p->rate*gt;
	p->alpha = (double)powf(ga,1.0f/n);

	for(i = 0; i < FDNORDER; i++)
	{
		p->fdngains[i] = -powf((float)p->alpha, p->fdnlens[i]);
	}
}

static inline void gverb_set_damping(ty_gverb *p, double a)
{
	unsigned int i;

	p->fdndamping = CLIP(a, 0.0f, 1.0f);
	for(i = 0; i < FDNORDER; i++)
	{
		damper_set(p->fdndamps[i],p->fdndamping);
	}
}

static inline void gverb_set_inputbandwidth(ty_gverb *p, double a)
{
	p->inputbandwidth = CLIP(a, 0.0f, 1.0f);
	damper_set(p->inputdamper,1.0f - p->inputbandwidth);
}

static inline void gverb_set_drylevel(ty_gverb *p, double a)
{
	a = CLIP(a, -90.0f, 0.0f);
	p->drylevel = DB_CO(a);
}

static inline void gverb_set_earlylevel(ty_gverb *p, double a)
{
	a = CLIP(a, -90.0f, 0.0f);
	p->earlylevel = DB_CO(a);
}

static inline void gverb_set_taillevel(ty_gverb *p, double a)
{
	a = CLIP(a, -90.0f, 0.0f);
	p->taillevel = DB_CO(a);
}

#endif
