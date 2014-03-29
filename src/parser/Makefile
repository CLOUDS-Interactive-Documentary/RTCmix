include ../../makefile.conf

DIRS = minc
SRCS = parse_with_minc.c
OBJS = parse_with_minc.o

all: $(DIRS) $(OBJS)
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) all; ) \
	done

parse_with_minc.o: parse_with_minc.c rtcmix_parse.h
	$(CC) $(CFLAGS) -c parse_with_minc.c

.PHONY: install clean

install:
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) install; ) \
	done

uninstall:
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) uninstall; ) \
	done

clean:
	$(RM) *.o depend core
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) clean; ) \
	done

cleanall:
	$(RM) *.o depend core
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) cleanall; ) \
	done

depend:
	-$(SHELL) -ec '$(CC) -M $(CFLAGS) $(PERL_CCFLAGS) $(PYTHON_CCFLAGS) $(SRCS)' > depend
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) depend; ) \
	done

