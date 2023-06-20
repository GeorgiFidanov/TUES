int switchState = 0;
int count = 0;

//setup
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  switchState = digitalRead(2); 	//HIGH or LOW based on whether the button is on or off
  if(switchState == HIGH){
    count++;
  }
  while(count <= 1) {
    //simon lies     	
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH); 
    delay (2500);
  }
  if(count %2 == 1){
    //simon did not say
    digitalWrite(3, LOW); 	
    digitalWrite(4, HIGH); 	
    digitalWrite(5, LOW);
    delay (2500);
  }
  if(count %2 ==0) {
    //simon said
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay (2500);
  }    
}	


/*
158 - 128 = 30-16 = 14 - 8 = 6 - 4 = 2 - 2 = 0
158 - 3 na 5ta 10000
158 - 81 = 77 - 27 = 50 - 27= 23 - 9 = 14 - 9 = 5 - 3 = 2 12212
158 - 64 = 94 - 64 = 30 - 16 = 14 - 4 = 10 - 4 = 6- 4 = 2213
0011 + 1010 = /00111010 - v golqm nds - ot 31 do 24, maluk ot 7 do 0\1101 = 11\tova sa stepeni na 2
1000 + 1100 = /10001100 - v golqm nds - ot 23 do 16, maluk ot 15 do 8\10100 = 19 
0001 + 0000 = /00010000 - v golqm nds - ot 15 do 8, maluk ot 23 do 16\0001 = 1 
1111 + 0010 = /11110010 - v golqm nds - ot 7 do 0, maluk ot 31 do 24\10001 = 17 = 48?
*/