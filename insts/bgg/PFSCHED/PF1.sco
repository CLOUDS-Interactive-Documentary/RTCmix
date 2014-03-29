rtsetparams(44100, 1)
load("PFSCHED")
load("WAVETABLE")

sent_envelope = maketable("line", 100, 0,0.0,  1,1.0)
value = makeconnection("pfbus", 1, 1.0)

wave = maketable("wave", 1000, "sine")

// PFSCHED has to start at time 0.  It is really only useful for
// imbedded applications
PFSCHED(0, 2.1, 1, sent_envelope)
WAVETABLE(0, 7.0, 20000*value, 8.00, 0.5, wave)

