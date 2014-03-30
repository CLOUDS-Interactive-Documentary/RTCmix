// From http://www.linuxjournal.com/article/5574

#ifndef _TIMES_H
#define _TIMES_H

#ifdef _WIN32
#include <sys/timeb.h>
#include <sys/types.h>
#include <winsock2.h>

#define __need_clock_t
#include <time.h>

//struct timezone 
//{
//  int  tz_minuteswest; /* minutes W of Greenwich */
//  int  tz_dsttime;     /* type of dst correction */
//};

// from linux's sys/times.h

//#include <features.h>

int gettimeofday(struct timeval *tv, void* tz);

/* Structure describing CPU time used by a process and its children.  */
struct tms
  {
    clock_t tms_utime;          /* User CPU time.  */
    clock_t tms_stime;          /* System CPU time.  */

    clock_t tms_cutime;         /* User CPU time of dead children.  */
    clock_t tms_cstime;         /* System CPU time of dead children.  */
  };

/* Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.  */
clock_t times (struct tms *__buffer);

typedef long long suseconds_t ;

#endif
#endif