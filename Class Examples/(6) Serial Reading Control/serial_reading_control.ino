#define redPin   11
#define greenPin 10
#define bluePin	 9	

int LEDColor;
int blinkQuantity;
int DELAY = 250;

void setup(){
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
  Serial.println("Select an LED to blink (1-Red, 2-Green, 3-Blue):");
  while(Serial.available()==0){}  // Waiting for some data
  LEDColor = Serial.parseInt();   // Rescue of that data
  
  Serial.println("How many times should it blink?");
  while(Serial.available()==0){}       // Waiting for some data
  blinkQuantity = Serial.parseInt();   // Rescue of that data
  
  for(int i=0 ; i<blinkQuantity ; i++){
    digitalWrite(12-LEDColor, HIGH);
    delay(DELAY);
    digitalWrite(12-LEDColor, LOW);
    delay(DELAY);
  }
}