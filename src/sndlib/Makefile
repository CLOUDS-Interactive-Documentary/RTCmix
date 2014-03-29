include ../../makefile.conf

OBJS = headers.o io.o extra.o

all: sndlib.a

sndlib.a: $(OBJS)
	$(RM) $@
	ar q $@ $(OBJS)
	$(RANLIB) $@
endif

install: all
uninstall:

clean: 
	$(RM) $(OBJS) sndlib.a

cleanall: clean

distclean: clean

