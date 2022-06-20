#define SOLARPIN A0
#define THRESHOLD 10
int count = 0;
int ambientReading = 0;
int flag = 0;
int pos = 0;

void setup() {
  pinMode(SOLARPIN, INPUT);
  Serial.begin(9600);

  ambientReading  = analogRead(SOLARPIN);
  //average = sensorValue;
}



void loop() {

  int reading = analogRead(SOLARPIN);
  int bits[8];



  if (reading > ambientReading + THRESHOLD) {
    count++;
    
    for (int i = 0; i < 8; i++) {
      if (analogRead(SOLARPIN) > ambientReading + THRESHOLD) {
        bits[i] = 1;
        flag++;
      }
      else {
        bits[i] = 0;
      }
      delay(10);
    }

    if (count % 10 == 0) {
      if ( (flag >= 9) && (flag < 21) ) {
        pos = 1;
        Serial.print(pos);
        flag = 0;
    }

     if ( (flag >= 21) && (flag < 43) ) {
        pos = 2;
        Serial.print(pos);
        flag = 0;
     }
      if ( flag > 48 ) {
        pos = 3;
        Serial.print(pos);
        flag = 0;
      }
    }
  }
}
