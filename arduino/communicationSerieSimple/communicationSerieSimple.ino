
#define usleep 10000
// constants won't change. They're used here to 
// set pin numbers:
const int txPin = 13;
const int rxPin = 12;
const int d0Pin = 2; //data pin 0
const int d1Pin = 3;
const int d2Pin = 4;
const int d3Pin = 5;
const int d4Pin = 6;
const int d5Pin = 7;
const int d6Pin = 8;
const int d7Pin = 9;
const int c0Pin = 10; //control pin0
const int c1Pin = 11; //control pin1

// variables will change:
int rxState = 0;         // variable for reading the pushbutton status
int initOK = 0;
int appareillage1=0;
int acknow=0;

void setup() {
  Serial.begin(9600);
  Serial.print("Begin OK\n");
  pinMode(d0Pin, OUTPUT);
  pinMode(d1Pin, OUTPUT);
  pinMode(d2Pin, OUTPUT);
  pinMode(d3Pin, OUTPUT);
  pinMode(d4Pin, OUTPUT);
  pinMode(d5Pin, OUTPUT);
  pinMode(d6Pin, OUTPUT);
  pinMode(d7Pin, OUTPUT);
  pinMode(c0Pin, OUTPUT);
  pinMode(c1Pin, OUTPUT);
  pinMode(rxPin, INPUT);      
  pinMode(txPin, OUTPUT);
  
  //init
//  digitalWrite(rxPin, LOW);
  digitalWrite(txPin, LOW);
  digitalWrite(d0Pin, LOW);
  digitalWrite(d1Pin, LOW);
  digitalWrite(d2Pin, LOW);
  digitalWrite(d3Pin, LOW);
  digitalWrite(d4Pin, LOW);
  digitalWrite(d5Pin, LOW);
  digitalWrite(d6Pin, LOW);
  digitalWrite(d7Pin, LOW);
  digitalWrite(c0Pin, LOW);
  digitalWrite(c1Pin, LOW);
  delay(1000);
  Serial.print("Setup OK\n");
}

void loop(){

  if (initOK ==0)
  {
    Serial.print("Debut init\n");
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
          Serial.print("Init OK\n");
        }
      }  
    }
  }
  else // System initialised
  {
    Serial.print("Jattends\n");
    if (rxState == HIGH) {
      Serial.print("Je demarre\n");
      digitalWrite(d0Pin, HIGH); //Bit de poids faible
      digitalWrite(d1Pin, LOW);
      digitalWrite(d2Pin, LOW);
      digitalWrite(d3Pin, LOW);
      digitalWrite(d4Pin, HIGH);
      digitalWrite(d5Pin, HIGH);
      digitalWrite(d6Pin, LOW);
      digitalWrite(d7Pin, HIGH);
      digitalWrite(c0Pin, LOW); //canal part 0
      digitalWrite(c1Pin, HIGH);//canal part 1
      delayMicroseconds(usleep);
      Serial.print("Je me reveille\n");
      digitalWrite(txPin, HIGH);// write 1 to tx.
      while(acknow==0) //wait ack from rx
      {
        Serial.print("J'attends la reponse\n");
        rxState = digitalRead(rxPin);
        if (rxState == LOW) { //ack ok --> write 0 to tx
          digitalWrite(txPin, LOW);
          acknow=1;
          initOK=1;
          Serial.print("Fini\n");

        }
      }
    }

  }
}






