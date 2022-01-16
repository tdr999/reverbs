y = load("intrare.dat");

c = load("iesireSimple.dat");

delay_ms = 90;
delay_sample = 44.1 * delay_ms;

ret = zeros(1, (length(y)+4000));

dry = 0.2;
wet =0.7;
scale = 1;

for i=1:length(y)
    if i>delay_sample
        ret(i) = scale*dry*y(i) + wet*y(i-delay_sample);
    elseif i> length(y) - 4000
        ret(i) = wet*y(i-delay_sample);
    else
        ret(i) = scale*dry*y(i);
    end

end

ret = int16(-ret);

FS = 44100;

dt = 1/FS;
t = 0:dt:(length(y)*dt)-dt;
tRET = 0:dt:(length(ret)*dt)-dt;

figure(1)
plot(tRET, int16(ret)); hold on ;
plot(tRET, c); 
legend('MATLAB Test Signal', 'C generated Signal')

player = audioplayer(int16(ret), 2*FS);
player.play();