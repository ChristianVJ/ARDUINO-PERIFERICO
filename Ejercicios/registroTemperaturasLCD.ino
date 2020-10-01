/* Programa que mide la temperatura y la muestra en una LCD*/

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
 // SECCIÓN LCD

  lcd.begin(16, 2); // Inicializar el tamaño de la pantalla
  lcd.setCursor(0,0); // Colocar el cursor
  lcd.write("Temperatura: ");  //Pintar
  lcd.setCursor(12,0);  // Colocar el cursor
  lcd.print(tempC);//Pintar
  lcd.setCursor(14,0); // Colocar el cursor
  lcd.write((char)223);//Pintar
  lcd.setCursor(15,0); // Colocar el cursor
  lcd.write("C"); //Pintar
  lcd.setCursor(0,1); // Colocar el cursor
  lcd.write("Lecturas: "); //Pintar
  lcd.setCursor(9,1);  // Colocar el cursor
  lcd.print(address);
  } 
}
