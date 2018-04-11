
#define usleep 10000
// constants won't change. They're used here to 
// set pin numbers:
const int txPin = 13;
const int rxPin = 12;
const int dPin[8] ={ 2,3,4,5,6,7,8,9}; //data pin 0
const int c0Pin = 10; //control pin0
const int c1Pin = 11; //control pin1

// variables will change:
int i;

void setup() {
  Serial.begin(9600);
  Serial.print("Begin OK\n");
  for (i = 0; i < 8; i++) {   
       pinMode(dPin[i], OUTPUT);
  }
  pinMode(c0Pin, OUTPUT);
  pinMode(c1Pin, OUTPUT);
  pinMode(rxPin, INPUT);      
  pinMode(txPin, OUTPUT);

  //init
  //  digitalWrite(rxPin, LOW);
  digitalWrite(txPin, LOW);
   for (i = 0; i < 8; i++) {   
      digitalWrite(dPin[i], LOW);
   }
  digitalWrite(c0Pin, LOW);
  digitalWrite(c1Pin, LOW);
  delay(1000);
  Serial.print("Setup OK\n");
}
// Read from analog:
int val1;
int val2;
int val3;
int chan=3;

void loop(){

  Serial.print("Debut init\n");
  while(digitalRead(rxPin)==LOW){ // Serial.print("Attends 1:");Serial.println(digitalRead(rxPin));
  }
  
  digitalWrite(txPin, HIGH);
  while(digitalRead(rxPin)==HIGH){  //Serial.print("Attends 2\n");
  }
  digitalWrite(txPin, LOW);
  Serial.print("Init OK\n");

  Serial.print("Jattends\n");
  while(digitalRead(rxPin)==LOW){  //Serial.print("Attends 3\n");
  }

  Serial.print("Je demarre\n");
  // read the input on analog pin 0:
  val1 = analogRead(A0);
  val2= analogRead(A1);
  val3 = 345;//analogRead(A2);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  for (i = 0; i < 8; i++) {   
      digitalWrite(dPin[i], (val3 & ( 1 << (i+0) ))>>(i+0));
      Serial.print((val3 & ( 1 << (i+0) ))>>(i+0));
    }
    Serial.println("");
    digitalWrite(c0Pin, (chan & ( 1 << 0 ))>>0);
    Serial.print((chan & ( 1 << 0 ))>>0);
    digitalWrite(c1Pin, (chan & ( 1 << 1 ))>>1);
    Serial.print( (chan & ( 1 << 1 ))>>1);
  Serial.println("");
}













