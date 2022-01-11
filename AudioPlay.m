
y = load("iesireEchoes.dat");

FS = 44100;
audiowrite("test.wav", int16(y), 2*FS);

player = audioplayer(int16(y), 2*FS);
player.play();

