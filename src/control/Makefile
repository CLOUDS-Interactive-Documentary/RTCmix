include ../../makefile.conf

# RLD
#	DIRS = common midi mouse display datafile pfbus
DIRS = maxmsp pfbus

all: $(DIRS) $(OBJS)
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) all; ) \
	done

.PHONY: install clean cleanall

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

ifeq ($(BUILDTYPE), STANDALONE)
depend:
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) depend; ) \
	done
endif

clean:
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) clean; ) \
	done

cleanall:
	@for DIR in $(DIRS); \
	do \
	  ( cd $$DIR; $(MAKE) $(MFLAGS) cleanall; ) \
	done
