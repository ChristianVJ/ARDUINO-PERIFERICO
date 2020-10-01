clear all; % borra todas variables de la memoria de MATLAB

fileName='u4';
[y, fs, nbits]=wavread(fileName);

fprintf('Information of the sound file "%s":\n', fileName);
fprintf('Duration = %g seconds\n', length(y)/fs);
fprintf('Sampling rate = %g samples/second\n', fs);
fprintf('Bit resolution = %g bits/sample\n', nbits);

fs = 44000;
nbits = 24;

sound(y,fs,nbits) %reproduce la musica 



