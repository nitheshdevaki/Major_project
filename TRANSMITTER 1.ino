
#define PIN1 D0

void setup() {                
  // initialize the digital pin as an output.
  pinMode(PIN1, OUTPUT); 
  
}

// the loop routine runs over and over again forever:
void loop() {
 
  
 int bits1[] = {HIGH, LOW, LOW, LOW, LOW, LOW,  LOW, LOW};
  
  // digitalWrite(PIN1, HIGH);   //Listen signal
    //delay(10);
    //digitalWrite(PIN1, LOW);


    for (int i = 0; i < 8; i++) {
      digitalWrite(PIN1, bits1[i]);
      delay(1);
    }  
  
}
