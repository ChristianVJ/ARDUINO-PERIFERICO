/*********************************************************************************************************************************************************************************************
Termómetro con almacenamiento en EEPROM (Electrically Erasable Progammable Read-Only Memory)
La o el EEPROM es una memoria en estado sólido, lo cual significa que no tiene partes móviles, haciéndola ideal para aplicaciones que deben estar en hambientes húmedos.

Éste proyecto lo que hace simplemente es leer la temperatura de un sensor análogo conectado a una Arduino, y almacenar los datos en la EEPROM.

Debido a la poca capacidad de la EEPROM (512 bytes) no podemos almacenar mucha información en ella continuamente (a diferencia de una memoria SD), a menos que la espera sea sumamente larga.
Lo que significa que para medición de temperatura durante periodos cortos es apenas suficiente.

Para este ejemplo usé simples matemáticas, necesito almacenar la temperatura durante 8 horas 15 minutos (desde las 22:30 a las 6:45).
Para convertir de horas a segundos
8.25 * 360000 = 2970000
Para calcular cuanto tiempo debe esperar la Arduino antes de tomar una lectura nueva tome 2970000/512 (512 es la cantidad bytes que la EEPROM puede almacenar)
esto da un total de 5800.78125 segundos de espera.

Pero para hacer las cosas más fáciles lo haré con 6000 o 6 segundos.

Ejemplo de un LM 35 con Arduino: https://arduinolab.wordpress.com/2012/04/16/arduino-con-termo-resistencia-lm35-6/

Elaborado por: Pablo Andrade Mejía
http://www.arduinolab.wordpress.com
*********************************************************************************************************************************************************************************************/
//Variables a declarar
#include <EEPROM.h> //Librería para controlar la EEPROM de la Arduino
#include <LiquidCrystal.h>
int input;
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12); 

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

float tempC;
int tempPin = 0;
int memFull = 12;//<---- Ésta parte sigue en proceso
int addr = 0; //Cantidad de espacios (bytes) iniciales

void setup()
{
Serial.begin(9600); //Abre el puerto serial a 9600 bps
  
}

void loop()
{

if (Serial.available()>0){

input = Serial.read();
  
if (input == 'w'){

tempC = analogRead(tempPin)*5/1024.0; //Toma los datos del sensor
tempC = tempC - 0.5;
tempC = tempC / 0.01;
Serial.println((byte)tempC); //Envía los datos al computador mediante el puerto serial
EEPROM.write(addr, tempC);
 addr = addr + 1; //Por cada dato recibido lo guarda en una de los 512 espacios disponibles en la EEPROM
  if (addr == 512) //Sí el número total de datos excede los 512 
    addr = 0; //Borrar todo y comenzar de nuevo
    digitalWrite(memFull, HIGH); //<---- Ésta parte sigue en proceso.
}

if (input == 'r'){
  
// read a byte from the current address of the EEPROM
  value = EEPROM.read(address);
  
  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();
  
  // advance to the next address of the EEPROM
  address = address + 1;
  
  // there are only 512 bytes of EEPROM, from 0 to 511, so if we're
  // on address 512, wrap around to address 0
   if (address == 512)
   address = 0;

}

if (input == 'b'){
 
// write a 0 to all 512 bytes of the EEPROM
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);

}


  lcd.begin(16, 2); 
  lcd.setCursor(0,0); 
  lcd.write("Temperatura: "); 
  lcd.setCursor(12,0); 
  lcd.print(tempC);
  lcd.setCursor(14,0); 
  lcd.write((char)223);
  lcd.setCursor(15,0); 
  lcd.write("C");
  lcd.setCursor(0,1); 
  lcd.write("Lecturas: "); 
  lcd.setCursor(9,1);  
  lcd.print(address);




  }



  
}





