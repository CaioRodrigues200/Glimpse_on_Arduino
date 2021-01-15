int YellowLED = 11;
int GreenLED = 12;
int BlueLED = 13;

//Declaring three constant variables associated with its own LED

void setup() {
pinMode(YellowLED,OUTPUT);
pinMode(GreenLED,OUTPUT);
pinMode(BlueLED,OUTPUT);
}

//Yellow LED blinking 5 times

void loop() { 
for(int i=0; i<=4; i++){ 
digitalWrite(YellowLED,HIGH);
delay(400);
digitalWrite(YellowLED,LOW);
delay(400);
}

//Green LED blinking 10 times

for(int i=0; i<=9; i++){ 
digitalWrite(GreenLED,HIGH);
delay(200);
digitalWrite(GreenLED,LOW);
delay(200);
}

//Blue LED blinking 20 times

for(int i=0; i<=19; i++){ 
digitalWrite(BlueLED,HIGH);
delay(100);
digitalWrite(BlueLED,LOW);
delay(100);
}
}