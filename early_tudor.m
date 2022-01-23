x = load("intrare.dat");

y_starcore = load("iesireEchoes.dat");

temporaryfile = fopen("iesireOctav.dat", "w+");


delay_ms = [50 80 100 160];
delay_sample = 44.1 * delay_ms;



dry = 0.6;
wet = [0.2 0.4 0.6 0.8];
scale = 1 / sum(wet);

temp = 0;


buf = zeros(delay_sample(4)); 
indiceBuf = 1;


len = length(x)


primaIntarziere = zeros(len, 'int16');
douaIntarziere = zeros(len, 'int16');
treiaIntarziere = zeros(len, 'int16');
patruIntarziere = zeros(len, 'int16');




primaIntarziere = x(1:1:(len - delay_sample(1)))*wet(1);
douaIntarziere = x(1:1:(len - delay_sample(2))))*wet(2);
treiaIntarziere = x(1:1:(len - delay_sample(3)))*wet(3);
patruIntarziere = x(1:1:(len - delay_sample(4)))*wet(4);

padding1 = zeros(delay_sample(1));
padding2 = zeros(delay_sample(2));
padding3 = zeros(delay_sample(3));
padding4 = zeros(delay_sample(4));

primaIntarzierePadat = [padding1; primaIntarziere];

padding1(end:end+length(primaIntarziere)+1) = primaIntarziere;



fclose(temporaryfile);
temp = load("iesireOctav.dat");

temp = temp *scale



ret = int16(temp);



FS = 44100;



figure(1)
plot(int16(ret)); hold on ;
plot(y_starcore); 
legend('MATLAB Test Signal', 'C generated Signal')

player = audioplayer(int16(ret), 2*FS);
player.play();