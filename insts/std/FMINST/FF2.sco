load("FMINST")
rtsetparams(44100, 2)
makegen(1, 24, 1000, 0, 0, 3.5,1, 7,0)
makegen(2, 10, 1000, 1)
makegen(3, 24, 1000, 0, 0, 5,1, 7, 0)
FMINST(0, 7, 10000, 8.00, 179, 0, 10, 0.1)
makegen(3, 24, 1000, 0,1, 7,0)
FMINST(3.5, 7, 10000, 8.07, 179, 0, 10, 0.9)
