/*
  ReadAnalogVoltage
 Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
 Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
const int ledPin =  13;      // the number of the LED pin
const int buttonPin = 2;     // the number of the pushbutton pin
const int NmoyenneRoulante = 150;

//float tabmoyenneRoulante0[NmoyenneRoulante];
//float tabmoyenneRoulante1[NmoyenneRoulante];
//float tabmoyenneRoulante2[NmoyenneRoulante];


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
//  pinMode(ledPin, OUTPUT);      
//  // initialize the pushbutton pin as an input:
//  pinMode(buttonPin, INPUT);    
}

// int buttonState = 0;         // variable for reading the pushbutton status
// Read from analog:
int sensorValue0;
int sensorValue1;
int sensorValue2;
//covert to voltage
float voltage0;
float voltage1;
float voltage2;

//float sum0=0;
//float sum1=0;
//float sum2=0;
//float sumc0=0;
//float sumc1=0;
//float sumc2=0;
//float ecarttype0;
//float ecarttype1;
//float ecarttype2;

int i=0;
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue0 = analogRead(A0);
  sensorValue1 = analogRead(A1);
  sensorValue2 = analogRead(A2);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  voltage0 = sensorValue0 * (5.0 / 1023.0);
  voltage1 = sensorValue1 * (5.0 / 1023.0);
  voltage2 = sensorValue2 * (5.0 / 1023.0);

//if (i==NmoyenneRoulante-1)
//  {
//    i=0;
//  }
//  else
//  {
//    i++;
//  }

//
//  sum0-=tabmoyenneRoulante0[i];
//  sum1-=tabmoyenneRoulante1[i];
//  sum2-=tabmoyenneRoulante2[i];
//  sumc0-=tabmoyenneRoulante0[i]*tabmoyenneRoulante0[i];
//  sumc1-=tabmoyenneRoulante1[i]*tabmoyenneRoulante1[i];
//  sumc2-=tabmoyenneRoulante2[i]*tabmoyenneRoulante2[i];

//  tabmoyenneRoulante0[i]=voltage0;
//  tabmoyenneRoulante1[i]=voltage1;
//  tabmoyenneRoulante2[i]=voltage2;
//
//  sum0+=tabmoyenneRoulante0[i];
//  sum1+=tabmoyenneRoulante1[i];
//  sum2+=tabmoyenneRoulante2[i];
//  sumc0+=tabmoyenneRoulante0[i]*tabmoyenneRoulante0[i];
//  sumc1+=tabmoyenneRoulante1[i]*tabmoyenneRoulante1[i];
//  sumc2+=tabmoyenneRoulante2[i]*tabmoyenneRoulante2[i];

//  ecarttype0=sqrt((sumc0/NmoyenneRoulante)-(sum0/NmoyenneRoulante)*(sum0/NmoyenneRoulante));
//  ecarttype1=sqrt((sumc1/NmoyenneRoulante)-(sum1/NmoyenneRoulante)*(sum1/NmoyenneRoulante));
//  ecarttype2=sqrt((sumc2/NmoyenneRoulante)-(sum2/NmoyenneRoulante)*(sum2/NmoyenneRoulante));

  Serial.print(voltage0);
  Serial.print("\t");
  Serial.print(voltage1);
  Serial.print("\t");
  Serial.print(voltage2);
//  Serial.print("\t");
//  Serial.print(ecarttype0);
//  Serial.print("\t");
//  Serial.print(ecarttype1);
//  Serial.print("\t");
//  Serial.print(ecarttype2);
  Serial.print("\n");
  delayMicroseconds(20000);
}

