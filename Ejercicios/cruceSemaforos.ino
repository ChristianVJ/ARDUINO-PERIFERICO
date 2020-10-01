/*
  Programa para un par de semaforos que cambian de uno
  a otro, y la implementacin de un boton para terminar
  el tiempo de la luz verde y pasar al otro.
*/
// Declaramos la variable para el pin del boton
const int button = 8; //Botón de cambio manual/automático
const int button2 = 9;//Botón para cambiar el semáforo
int num=0;
int state, state2;

void setup() {
  // Con un ciclo activamos los pines del 2 al 7 como salidas
  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
  // El pin del boton lo ponemos como entrada
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
}

void manual(){
  int valor;
  for (int pin = 2; pin <= 7; pin++) {
        digitalWrite(pin, LOW);
  }

  switch(num){
    case 0: 
           digitalWrite(2, HIGH);
           digitalWrite(7, HIGH);
           delay(3000);
           break;
    case 1:
          digitalWrite(7, HIGH);
          digitalWrite(3, HIGH);
          delay(500);
          break;
    case 2:
          digitalWrite(5, HIGH);
          digitalWrite(4, HIGH);
          delay(3000);
          break;
    case 3:
          digitalWrite(6, HIGH);
          digitalWrite(4, HIGH);
          delay(500);
      }
}

// Iniciamos nuestro semaforo
void loop() {
  
    state=digitalRead(button); //Detecta si el botón ha pasado a otro estado
    state2=digitalRead(button2); //Detecta si el segundo botón se ha pulsado
    if(state==0 && state2==0){
    manual();
    num++;
    if(num>4){
      num=0;
    }
    }
   

    if(state==1){
      state=0;
      while(state==0){
        if(state2==1){
              if(num == 0){
                 num=1;
                }
               if(num == 2){
                 num=3;
                }
          state2=0;
          }
        else
         num++;
         
            if(num>4){
            num=0;
       }
        manual();
       }
    }
}
