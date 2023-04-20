int light;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  light = analogRead(A0);
  if(light<300){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
  
  Serial.println(light);
  delay(100);
}
                       
