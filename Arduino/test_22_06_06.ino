//set pin numbers
//const won't change
const int ledPin = 13;   //the number of the LED pin
const int ldrPin = A0;  //the number of the LDR pin


void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  //initialize the LED pin as an output
  pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input
}

void loop() {

  int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value
   
  if (ldrStatus >= 600) {

    digitalWrite(ledPin, HIGH);               //turn lamps off
    Serial.println("----------");
    Serial.println(ldrStatus);
    delay(5000);
    
   }
  else {

    digitalWrite(ledPin, LOW);          
    Serial.println("LDR is DARK, lamps are ON");
    Serial.println(ldrStatus);
    delay(5000);
  }
}
