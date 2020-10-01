
void setup () {

Serial.begin(9600);    // abre el Puerto serie
pinMode (2, INPUT);     // Pulsador de entrada
randomSeed(analogRead(0));  // Generador de numeros aleatorios

  // LEDs de salida
   pinMode (7, OUTPUT);
   pinMode (8, OUTPUT);
   pinMode (9, OUTPUT);
   pinMode (10, OUTPUT);
   pinMode (11, OUTPUT);
   pinMode (12, OUTPUT);
   pinMode (13, OUTPUT);    
 
    
   //Apaga todos los leds
   digitalWrite (7, LOW);
   digitalWrite (8, LOW);
   digitalWrite (9, LOW);
   digitalWrite (10, LOW);
   digitalWrite (11, LOW);
   digitalWrite (12, LOW);
   digitalWrite (13, LOW);   
 
}
 

void rodarElDado (unsigned char num) {

  switch (num) {
            
    case 1: // 1
            digitalWrite (7, LOW);
            digitalWrite (8, LOW);
            digitalWrite (9, LOW);
            digitalWrite (10, LOW);
            digitalWrite (11, HIGH);
            digitalWrite (12, LOW);
            digitalWrite (13, LOW);          
            break;
            
    case 2: // 2
            digitalWrite (7, LOW);
            digitalWrite (8, HIGH);
            digitalWrite (9, LOW);
            digitalWrite (10, LOW);
            digitalWrite (11, LOW);
            digitalWrite (12, HIGH);
            digitalWrite (13, LOW);  
            break;
            
    case 3: // 3
            digitalWrite (7, LOW);
            digitalWrite (8, HIGH);
            digitalWrite (9, LOW);
            digitalWrite (10, LOW);
            digitalWrite (11, HIGH);
            digitalWrite (12, HIGH);
            digitalWrite (13, LOW); 
            break;
            
    case 4: // 4
            digitalWrite (7, HIGH);
            digitalWrite (8, HIGH);
            digitalWrite (9, LOW);
            digitalWrite (10, LOW);
            digitalWrite (11, LOW);
            digitalWrite (12, HIGH);
            digitalWrite (13, HIGH); 
            break;
            
    case 5: // 5
            digitalWrite (7, HIGH);
            digitalWrite (8, HIGH);
            digitalWrite (9, LOW);
            digitalWrite (10, LOW);
            digitalWrite (11, HIGH);
            digitalWrite (12, HIGH);
            digitalWrite (13, HIGH); 
            break;
            
    case 6: // 6
            digitalWrite (7, HIGH);
            digitalWrite (8, HIGH);
            digitalWrite (9, HIGH);
            digitalWrite (10, HIGH);
            digitalWrite (11, LOW);
            digitalWrite (12, HIGH);
            digitalWrite (13, HIGH);
            break;
        
    default:
    case 0:  //Apagar todos los leds
            digitalWrite (7, LOW);
            digitalWrite (8, LOW);
            digitalWrite (9, LOW);
            digitalWrite (10, LOW);
            digitalWrite (11, LOW);
            digitalWrite (12, LOW);
            digitalWrite (13, LOW);
            break;
            
  }
  
 
}



void dadoElectronico () {

   unsigned int numero;
  
  while (!digitalRead (2));     // Pulsar boton
  rodarElDado (0);              // LEDS OFF
  while (digitalRead (2));      // Soltar boton

for (int i = 0; i < 5; i++){
  numero = random(1, 7);        // Numero aleatorio
  rodarElDado (numero);         // Mostrar el numero en el dado
  delay(300);
}

  numero = random(1, 7);        // Numero aleatorio
  Serial.println(numero);       // Numero aleatorio en el monitor serie
  rodarElDado (numero);         // Mostrar el numero en el dado

 
}

void probadorDado() {
  
   unsigned int numero;
   
  while (!digitalRead (2));     // Pulsar boton
  rodarElDado (0);              // LEDS OFF
  while (digitalRead (2));      // Soltar boton
  
  for (int contador = 0; contador < 200; contador++){
  
  numero = random(1, 7);        // Numero aleatorio
  Serial.println(numero);       // Numero aleatorio en el monitor serie
  rodarElDado (numero);         // Mostrar el numero en el dado
  delay(50);
 }
 
}


void loop () {
  
// dadoElectronico();
probadorDado();
 
}
