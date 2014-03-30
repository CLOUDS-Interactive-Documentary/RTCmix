
#include "times.h"
//#include <windows.h> //I've ommited this line.

//#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
//  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
//#else
//  #define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
//#endif

//int gettimeofday(struct timeval *tv, struct timezone *tz)
//{
//  FILETIME ft;
//  unsigned __int64 tmpres = 0;
//  static int tzflag;
// 
//  if (NULL != tv)
//  {
//    GetSystemTimeAsFileTime(&ft);
// 
//    tmpres |= ft.dwHighDateTime;
//    tmpres <<= 32;
//    tmpres |= ft.dwLowDateTime;
// 
//    /*converting file time to unix epoch*/
//    tmpres -= DELTA_EPOCH_IN_MICROSECS; 
//    tmpres /= 10;  /*convert into microseconds*/
//    tv->tv_sec = (long)(tmpres / 1000000UL);
//    tv->tv_usec = (long)(tmpres % 1000000UL);
//  }
// 
//  if (NULL != tz)
//  {
//    if (!tzflag)
//    {
//      _tzset();
//      tzflag++;
//    }
//    tz->tz_minuteswest = _timezone / 60;
//    tz->tz_dsttime = _daylight;
//  }
// 
//  return 0;
//}

int gettimeofday(struct timeval* t,void* timezone)
{       struct _timeb timebuffer;
        _ftime( &timebuffer );
        t->tv_sec=timebuffer.time;
        t->tv_usec=1000*timebuffer.millitm;
        return 0;
}

clock_t times (struct tms *__buffer) {

        __buffer->tms_utime = clock();
        __buffer->tms_stime = 0;
        __buffer->tms_cstime = 0;
        __buffer->tms_cutime = 0;
        return __buffer->tms_utime;
}

//extern int gettimeofday(struct timeval* t,void* timezone);