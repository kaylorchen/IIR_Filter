clear all
figure(1)
clf
data1 =  load('record-before.txt');
data1 =  transpose( data1);

data2 =  load('result.txt');
data2 =  transpose( data2);
data2 = data2(1:length(data2)-1);
plot(data2);
hold on;

Hd = lowpass;
output=filter(Hd,data1);
Hd = highpass;
output=filter(Hd,output);

plot(output/2);
hold on;

figure(2)
clf
plot(output - data2)

figure(3)
clf
y = fft(data2);
n = length(data2);                         
fshift = (-n/2:n/2-1)*(48000/n);
yshift = fftshift(y);
plot(fshift,abs(yshift))
hold on;
title('Magnitude')
y = fft(output);
yshift = fftshift(y);
plot(fshift,-abs(yshift),'r')
xlim([-10,400])