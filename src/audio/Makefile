include ../../makefile.conf

AUDIOLIB = librtaudio.a

INCLUDES += -I../sndlib -I../rtcmix -I$(INCLUDEDIR)
CFLAGS += -DCMIX_LEGACY

OBJECTS =  AudioDevice.o AudioIODevice.o AudioDeviceImpl.o \
		   ThreadedAudioDevice.o AudioOutputGroupDevice.o \
		   DualOutputAudioDevice.o AudioFileDevice.o \
		   NetAudioDevice.o audio_dev_creator.o sndlibsupport.o

ifeq ($(ARCH),MACOSX)
   ifeq ($(BUILDTYPE), STANDALONE)
		OBJECTS += OSXAudioDevice.o
   endif
endif

SNDLIB = ../sndlib/sndlib.a

all:	$(AUDIOLIB)

$(AUDIOLIB):	$(OBJECTS)
	$(RM) $@
	ar q $@ $(OBJECTS)
	$(RANLIB) $@

.c.o:
	$(CC) $(CFLAGS) $(SOUND_DRIVER) -c $< -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $(SOUND_DRIVER) -c $< -o $@

depend:

-include depend

install: all
uninstall:

clean:
	$(RM) $(OBJECTS) $(AUDIOLIB)

cleanall: clean
	$(RM) depend

