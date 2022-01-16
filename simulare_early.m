y = load("intrare.dat");

c = load("iesireEchoes.dat");

delay_ms = [50 80 100 160];
delay_sample = 44.1 * delay_ms;

ret = zeros(1, (length(y)+delay_sample(4)));

dry = 0.6;
wet = [0.2 0.4 0.6 0.8];
scale = 1 / sum(wet);

for i=1:length(y)
        if i<=delay_sample(1)
             ret(i) = scale*dry*y(i);

        elseif i>delay_sample(1) && i<=delay_sample(2)
             aux = wet(1)*y(i-delay_sample(1));
             ret(i) = scale*aux + scale*dry*y(i);
        elseif i>delay_sample(2) && i<=delay_sample(3)
             for j = 1:2
                 if j == 1
                    aux = wet(j)*y(i-delay_sample(j));
                 else
                    aux = wet(j)*y(i-delay_sample(j)+delay_sample(j-1));
                 end
             end
             ret(i) = scale*aux + scale*dry*y(i);

        elseif i>delay_sample(3) && i<=delay_sample(4)
             for j = 1:3
                aux = wet(j)*y(i-delay_sample(j));
             end
             ret(i) = scale*aux + scale*dry*y(i);

        elseif i>delay_sample(4) && i<=length(y) - delay_sample(4)
             for j = 1:4
                aux = wet(j)*y(i-delay_sample(j));
             end
             ret(i) = scale*aux + scale*dry*y(i);
        elseif i> length(y) - delay_sample(4)
            for j = 1:4
                aux = wet(j)*y(i-delay_sample(j));
            end
            ret(i) = scale*aux;
        end
end

ret = int16(ret);

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