/*

 
 
 */

// constants won't change. They're used here to 
// set pin numbers:
const int txPin = 0;
const int rxPin = 1;
const int d0Pin = 2; //data pin 0
const int d1Pin = 3;
const int d2Pin = 4;
const int d3Pin = 5;
const int d4Pin = 6;
const int d5Pin = 7;
const int d6Pin = 7;
const int d7Pin = 8;
const int d8Pin = 9; //data pin 8
const int c0Pin = 10; //control pin0
const int c1Pin = 11; //control pin1

// variables will change:
int rxState = 0;         // variable for reading the pushbutton status
int initOK = 0;
int appareillage1=0;
int acknow=0;

void setup() {
  pinMode(d0Pin, OUTPUT);
  pinMode(d1Pin, OUTPUT);
  pinMode(d2Pin, OUTPUT);
  pinMode(d3Pin, OUTPUT);
  pinMode(d4Pin, OUTPUT);
  pinMode(d5Pin, OUTPUT);
  pinMode(d6Pin, OUTPUT);
  pinMode(d7Pin, OUTPUT);
  pinMode(d8Pin, OUTPUT);
  pinMode(c0Pin, OUTPUT);
  pinMode(c1Pin, OUTPUT);
  pinMode(rxPin, INPUT);      
  pinMode(txPin, OUTPUT);
}

void loop(){

  if (initOK ==0)
  {
    // read the state of the rx entry:
    rxState = digitalRead(rxPin);
    if (rxState == HIGH) {     
      digitalWrite(txPin, HIGH);// write 1 to tx.
      while(appareillage1==0) //wait ack from rx
      {
        rxState = digitalRead(rxPin);
        if (rxState == LOW) { //ack ok --> write 0 to tx
          digitalWrite(txPin, LOW);
          appareillage1=1;
          initOK=1;
        }
      }  
    }
  }
  else // System initialised
  {
    if (rxState == HIGH) {

      digitalWrite(d0Pin, HIGH); //Bit de poids faible
      digitalWrite(d1Pin, LOW);
      digitalWrite(d2Pin, LOW);
      digitalWrite(d3Pin, LOW);
      digitalWrite(d4Pin, HIGH);
      digitalWrite(d5Pin, HIGH);
      digitalWrite(d6Pin, LOW);
      digitalWrite(d7Pin, LOW);
      digitalWrite(d8Pin, HIGH);
      digitalWrite(c0Pin, LOW); //canal part 0
      digitalWrite(c1Pin, HIGH);//canal part 1
      delayMicroseconds(100);
      digitalWrite(txPin, HIGH);// write 1 to tx.
      while(acknow==0) //wait ack from rx
      {
        rxState = digitalRead(rxPin);
        if (rxState == LOW) { //ack ok --> write 0 to tx
          digitalWrite(txPin, LOW);
          acknow=1;
          initOK=1;

        }
      }
    }

  }
}





