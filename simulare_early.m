y = load("intrare.dat");
c = load("iesireEchoes.dat");


delay_ms = [30 50 80 90];
delay_sample = 44.1 * delay_ms;

dry = 0.6;
wet = [0.2 0.4 0.6 0.8];
scale = 1 / (dry+sum(wet));
 
line_dry = (dry*scale).*y;
line1 = wet(1) .* echo_gen([0 y]', 44.1, delay_ms(1), scale)';
line2 = wet(2) .* echo_gen([0 y]', 44.1, delay_ms(2), scale)';
line3 = wet(3) .* echo_gen([0 y]', 44.1, delay_ms(3), scale)';
line4 = wet(4) .* echo_gen([0 y]', 44.1, delay_ms(4), scale)';

line_dry = padarray(line_dry, [0, length(line4) - length(line_dry)], 0, "post");
line1 = padarray(line1, [0, length(line4) - length(line1)], 0 , "post"); 
line2 = padarray(line2, [0, length(line4) - length(line2)],0, "post"); 
line3 = padarray(line3, [0,length(line4) - length(line3)],0, "post"); 
ret = line_dry+line1+line2+line3+line4;

ret = int16(ret);
FS = 44100;

tRET = 1:1:(length(ret));
tC= 1:1:length(c);

figure(1)
plot(tC, int16(ret)); hold on ;
plot(tRET, int16(c)); 
legend('MATLAB Test Signal', 'C generated Signal')

player = audioplayer(int16(c), 2*FS);
player.play();