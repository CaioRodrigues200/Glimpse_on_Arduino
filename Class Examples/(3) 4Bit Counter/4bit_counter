int pin2=2;
int pin3=3;
int pin4=4;
int pin5=5;
int WaitTime = 1000; // Delay time preset

void setup() {
pinMode(pin2,OUTPUT);
pinMode(pin3,OUTPUT);
pinMode(pin4,OUTPUT);
pinMode(pin5,OUTPUT);
}

void loop() { 
  for(int count=0; count<=15; count++){
    if(count%2 == 1) // Bit1 evaluation
      digitalWrite(pin2,HIGH);
    else
      digitalWrite(pin2,LOW);
    
    if(count%4 >= 2) // Bit2 evaluation
      digitalWrite(pin3,HIGH);
    else
      digitalWrite(pin3,LOW);
    
    if(count%8 >= 4) // Bit3 evaluation
      digitalWrite(pin4,HIGH);
    else
      digitalWrite(pin4,LOW);
    
    if(count > 7) // Bit4 evaluation
      digitalWrite(pin5,HIGH);
    else
      digitalWrite(pin5,LOW);
    
    delay(WaitTime);
  }
}