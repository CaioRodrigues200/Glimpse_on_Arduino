#define PotPin       A0
#define LowBand      11
#define SuitableBand 10
#define HighBand      9

float PotVoltage, PotResistance; 
float PotMxResistance = 10; // Potentiometer maximum resistance in Kilo-Ohms
int Delay = 200;

void setup(){
	Serial.begin(9600);
 	pinMode(PotPin, INPUT);
  	pinMode(LowBand, OUTPUT);
    pinMode(SuitableBand, OUTPUT);
    pinMode(HighBand, OUTPUT);
}

void loop(){
  
	  PotVoltage = analogRead(PotPin);
    PotResistance = PotMxResistance - ((10.0/1023.0) * PotVoltage);
    // 

  	Serial.print("Potentiometer Resistance: ");
  	Serial.print(PotResistance);
 	  Serial.println("Kilo-Ohms");
  	
  	if(PotResistance >= 9){
      digitalWrite(HighBand, HIGH);
  	  digitalWrite(LowBand, LOW);
      digitalWrite(SuitableBand, LOW);
    }
 	  else if(PotResistance <= 1){
      digitalWrite(HighBand, LOW);
  	  digitalWrite(LowBand, HIGH);
      digitalWrite(SuitableBand, LOW);
    }
    else{
      digitalWrite(HighBand, LOW);
  	  digitalWrite(LowBand, LOW);
      digitalWrite(SuitableBand, HIGH);
    }
  	
  	delay(Delay);
}	