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




% for i=1:length(x)
%   indiceBuf = mod(indiceBuf, delay_sample(4));
%   buf(indiceBuf) = x(i);
%   indiceBuf = indiceBuf + 1
%   temp = 0;
%   for j=1:length(delay_sample)
%     
%     if (indiceBuf - delay_sample(j) < 0)
%       temp = temp + buf(indiceBuf + delay_sample(4) - delay_sample(j))*wet(j)
%     else
%       temp = temp + buf(indiceBuf - delay_sample(j)) * wet(j)
%     end
%     
%   end
%   fprintf(temporaryfile, "%d ", temp);
%   print(temp);
% end


primaIntarziere[,]




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