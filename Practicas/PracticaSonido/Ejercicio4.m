
fs=44100; %f. muestreo
duracion=5;
senal_salida=audiorecorder(fs,16,1);%Creacion del objeto de grabacion
msgbox('Empezando Grabacion',' Grabadora '); %Mensaje de informacion
recordblocking(senal_salida,duracion);%Grabacion del sonido
msgbox('Terminando Grabacion',' Grabadora ');%Mensaje de informacion
%Paso los valores del objeto a una señal
senal_grabada=getaudiodata(senal_salida, 'single');
%Grabamos y guardamos la señal
wavwrite(senal_grabada,fs,uiputfile({'*.wav'},'Guardar como'));

