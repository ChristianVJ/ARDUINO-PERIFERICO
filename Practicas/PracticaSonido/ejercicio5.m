clear all; % borra todas variables de la memoria de MATLAB
tiempo = 23.7;
frecMuestreo = 44100;
fileName='sound.wav';
fileName2='sound.wav';
[y, fs, nbits]=wavread(fileName);%% datos, frecuencia, bits por dato
[y2, fs2, nbits2]=wavread(fileName2);%% datos, frecuencia, bits por dato


if fs==frecMuestreo && fs2==frecMuestreo %%Si las frecuencias de muestreo no son iguales
    fprintf('Los sonidos deben tener la misma frecuencia de muestreo\n');
end

N = length(y);

if N/fs < tiempo %%Si el tiempo en el que hay que insertar el segundo archivo es mayor que el primero
   sound(y,fs,nbits) %reproduce la musica 
end

sound(y3,(N/fs),nbits) %reproduce la musica 

 

