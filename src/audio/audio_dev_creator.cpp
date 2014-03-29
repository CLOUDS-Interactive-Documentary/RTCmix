// audio_dev_creator.cpp
//
// These functions coordinate the presence of multiple supported audio device
// types on a single machine.  It builds a database of creators and recognizers
// based upon the compile options, and uses that to determine which object
// to build based on the passed-in descriptor.

#include <stdio.h>

#include <ugens.h>

#include "OSXAudioDevice.h"

#include "AudioIODevice.h"

typedef AudioDevice * (*CreatorFun)(const char *, const char *, int mode);

struct AudioDevEntry {
	bool		(*recognizer)(const char *desc);
	CreatorFun	creator;
};

static const AudioDevEntry s_AudioDevEntries[] = {
	{ NULL, NULL }
};

AudioDevice *
createAudioDevice(const char *inputDesc,
				  const char *outputDesc,
				  bool recording, bool playing)
{
	CreatorFun iCreator = NULL, oCreator = NULL;
	AudioDevice *theDevice = NULL;
	const AudioDevEntry *currentEntry;

	if (recording) {
		// Search for creator for inputDesc.
		for (currentEntry = s_AudioDevEntries;
			 currentEntry->recognizer != NULL;
			 ++currentEntry)
		{
			if (currentEntry->recognizer(inputDesc) == true) {
				iCreator = currentEntry->creator;
				break;
			}
		}
		if (iCreator == NULL) {
			fprintf(stderr, "Unrecognized input device name '%s'.\n",
				inputDesc);
			return NULL;
		}
	}
	if (playing) {
		// Search for creator for outputDesc.
		for (currentEntry = s_AudioDevEntries;
			 currentEntry->recognizer != NULL;
			 ++currentEntry)
		{
			if (currentEntry->recognizer(outputDesc) == true) {
				oCreator = currentEntry->creator;
				break;
			}
		}
		if (oCreator == NULL) {
			fprintf(stderr, "Unrecognized output device name '%s'.\n",
				outputDesc);
			return NULL;
		}
	}
	// Handle full duplex requests.
	if (recording && playing) {
		AudioDevice *fullDuplexDevice = NULL;
		// If same HW for input and output, try to create a single
		// full-duplex device.
		if (iCreator == oCreator) {		
			fullDuplexDevice = iCreator(inputDesc,
										outputDesc,
										AudioDevice::RecordPlayback);
			
		}
		// If that failed, OR the input and output HW are different, create
		// a compound device from the two, and drive it via input.
		if (fullDuplexDevice == NULL) {
			AudioDevice *inDev = iCreator(inputDesc, NULL, AudioDevice::Record);
			AudioDevice *outDev = oCreator(NULL, outputDesc, AudioDevice::Playback);
			if (!inDev) {
				fprintf(stderr, "Failed to create input audio device!\n");
				delete outDev;
				return NULL;
			}
			else if (!outDev) {
				fprintf(stderr, "Failed to create output audio device!\n");
				delete inDev;
				return NULL;
			}

			bool forceInputActive = false;
			fullDuplexDevice = new AudioIODevice(inDev, outDev, forceInputActive);
		}
		theDevice = fullDuplexDevice;
	}
	// Handle half-duplex requests.
	else theDevice = (recording) ?
						iCreator(inputDesc, NULL, AudioDevice::Record)
						: oCreator(NULL, outputDesc, AudioDevice::Playback);
						
	return theDevice;
}
