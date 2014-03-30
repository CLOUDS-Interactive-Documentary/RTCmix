
#include <ugens.h>
#include <sndlibsupport.h>
#include <sfheader.h>

/* Used to determine if we should swap endian-ness */
extern int swap;       /* defined in check_byte_order.c */
int swap_bytes[NFILES];
static short is_Next[NFILES];
extern short isNext;

/* size of buffer to allocate.  this is no longer user-configurable */
/* JGG: might want to make this 64*1024 in Linux */
off_t nbytes = 32768;          /* exported only for the sake of sfcopy.c */

static int play_is_on=0;
int  sfd[NFILES];            /* soundfile descriptors */
int  pointer[NFILES];	     /* to be used as pointer within sound buffer */
int  bufsize[NFILES];        /* word length of buffer */

char *sndbuf[NFILES];        /* address of buffer */
static char *peak[NFILES];          /* array to store peak amplitude for nchannels */
static char *peakloc[NFILES];       /* overall peak amplitude */
			   
char wipe_is_off[NFILES];    /* this is for wipeout */
char peakoff[NFILES];        /* this will set peak test on or off*/
static float punch[NFILES];	     /* punch alteration flags */
static char istape[NFILES];         /* flag to see if it is a tape unit */
static double starttime[NFILES];    /* to save starting time of note */
static off_t  originalsize[NFILES];  /* to save byte length of file */
off_t  filepointer[NFILES];   /* to save current pointer in file */
int status[NFILES];	     /* save read/write flage as well */
int isopen[NFILES];	     /* open status */
int headersize[NFILES];      /* to accomodate bsd and next headers */

SFHEADER      sfdesc[NFILES];
SFMAXAMP      sfm[NFILES];
struct stat   sfst[NFILES];
