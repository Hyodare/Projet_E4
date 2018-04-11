
#define usleep 10000

#define ledON
// constants won't change. They're used here to 
// set pin numbers:
const int txPin = 13;
const int rxPin = 12;
const int dPin[8] ={ 
  2,3,4,5,6,7,8,9}; //data pin 0
const int c0Pin = 10; //control pin0
const int c1Pin = 11; //control pin1
const int aPin[3] ={ 
  A5,A4,A3}; //sensor pin
#ifdef ledON
const int led0Pin = A0;
const int led1Pin = A1;
#endif
// variables will change:
int i;
int iAnalog;
int valRead;

void setup() {
#ifdef ledON
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led0Pin, LOW);
#endif
  //Serial.begin(9600);
  //Serial.print("Debut Setup\n");
  for (i = 0; i < 8; i++) {   
    pinMode(dPin[i], OUTPUT);
  }
  pinMode(c0Pin, OUTPUT);
  pinMode(c1Pin, OUTPUT);
  pinMode(rxPin, INPUT);      
  pinMode(txPin, OUTPUT);
  pinMode(txPin, OUTPUT);
#ifdef ledON
  pinMode(led0Pin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
#endif
  for (i = 0; i < 3; i++) {   
    pinMode(aPin[i], INPUT);
  }

  digitalWrite(txPin, LOW);
  for (i = 0; i < 8; i++) {   
    digitalWrite(dPin[i], LOW);
  }
  digitalWrite(c0Pin, LOW);
  digitalWrite(c1Pin, LOW);
  iAnalog=0;
  delay(1000);
  //Serial.print("Fin Setup\n");
}
// Read from analog:

void loop(){
  //Serial.print("Debut init\n");
  while(digitalRead(rxPin)==LOW){ // //Serial.print("Attends 1:");//Serial.println(digitalRead(rxPin));
  }

  digitalWrite(txPin, HIGH);
  while(digitalRead(rxPin)==HIGH){  ////Serial.print("Attends 2\n");
  }
  digitalWrite(txPin, LOW);
  //Serial.print("Fin Init\n");



  while (1){ //send data
    //Serial.print("Debut transmission - Attente de Rx Low\n");
    while(digitalRead(rxPin)==LOW){  ////Serial.print("Attends 3\n");
    }
#ifdef ledON
    digitalWrite(led0Pin, HIGH);
    digitalWrite(led1Pin, LOW);
#endif

    //Serial.print("Rx recu. Lecture d'une pin analogique\n");
    
    valRead = analogRead(dPin[iAnalog]);// read the input on analog pin
    for (i = 0; i < 8; i++) {   
      digitalWrite(dPin[i], (valRead & ( 1 << (i+2) ))>>(i+2));
      //Serial.print((valRead & ( 1 << (i+2) ))>>(i+2));
    }
    //Serial.println("");
    digitalWrite(c0Pin, (iAnalog & ( 1 << 0 ))>>0);
    //Serial.print((iAnalog & ( 1 << 0 ))>>0);
    digitalWrite(c1Pin, (iAnalog & ( 1 << 1 ))>>1);
    //Serial.print( (iAnalog & ( 1 << 1 ))>>1);
    //Serial.println("");
    digitalWrite(txPin, HIGH);// fin de setup les datas
    //Serial.print("Attente confirmation reception\n");
    while(digitalRead(rxPin)==HIGH){  ////Serial.print("Attends 2\n");
    }
    digitalWrite(txPin, LOW);
#ifdef ledON
    digitalWrite(led0Pin, LOW);
    digitalWrite(led1Pin, HIGH);
#endif
    iAnalog=(iAnalog+1)%3;
    //Serial.print("Fin transmission\n");
  }
}















