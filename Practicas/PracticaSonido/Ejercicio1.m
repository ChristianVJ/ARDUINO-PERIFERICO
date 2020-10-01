clc
close all
clear

[yy,f,bits]=wavread('mika_relax'); %% datos, frecuencia, bits por dato
eje=length(yy); %%ndy= número de datos de y
xy=linspace(0,60,eje); %% dibuja eje de abscisas de 0 a 60 segundos

N=length(yy); %%ndy= número de datos de y. Se crean los vectores para 2 canales.
canal1=zeros(N,1);
canal2=zeros(N,1);

for i=1:N
canal1(i,1)=yy(i,1);
canal2(i,1)=yy(i,2);
end

subplot(2,1,1),plot(xy,canal1,'b');
xlabel('Tiempo [s]'),ylabel('Amplitud') %% definir ejes
title('Canal 1') %% titulo
grid

subplot(2,1,2),plot(xy,canal2,'r');
xlabel('Tiempo [s]'),ylabel('Amplitud') %% definir ejes
title('Canal 2') %% titulo
grid