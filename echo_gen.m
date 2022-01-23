function output = echo_gen(in,fs,delay,gain)
ds = floor(fs*delay)-1;
output =zeros(length(in)+ds,1);
output(ds+(1:length(in)))= in*gain;
end