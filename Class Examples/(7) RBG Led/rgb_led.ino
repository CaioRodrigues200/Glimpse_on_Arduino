// Avaliable colors: Red, Blue, Green, Purple, Yellow, Aqua, Orange, Pink

#define redPin   13
#define bluePin	 12	
#define greenPin 11

String LEDcolor;

void setup(){
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop(){
    Serial.println("Insert the color you want to show:");
    while(Serial.available()==0){}
    LEDcolor = Serial.readString(); // Receive an string

     if(LEDcolor == "off" || LEDcolor == "Off"){
        digitalWrite(redPin, LOW);
        digitalWrite(bluePin, LOW);
        digitalWrite(greenPin, LOW);
    }

    if(LEDcolor == "red" || LEDcolor == "Red"){
        digitalWrite(redPin, HIGH);
        digitalWrite(bluePin, LOW);
        digitalWrite(greenPin, LOW);
    }

     if(LEDcolor == "blue" || LEDcolor == "Blue"){
        digitalWrite(redPin, LOW);
        digitalWrite(bluePin, HIGH);
        digitalWrite(greenPin, LOW);
    }

     if(LEDcolor == "green" || LEDcolor == "Green"){
        digitalWrite(redPin, LOW);
        digitalWrite(bluePin, LOW);
        digitalWrite(greenPin, HIGH);
    }

     if(LEDcolor == "purple" || LEDcolor == "Purple"){
        digitalWrite(redPin, HIGH);
        digitalWrite(bluePin, HIGH);
        digitalWrite(greenPin, LOW);
    }

         if(LEDcolor == "yellow" || LEDcolor == "Yellow"){
        digitalWrite(redPin, HIGH);
        digitalWrite(bluePin, LOW);
        digitalWrite(greenPin, HIGH);
    }

             if(LEDcolor == "aqua" || LEDcolor == "Aqua"){
        digitalWrite(redPin, LOW);
        digitalWrite(bluePin, HIGH);
        digitalWrite(greenPin, HIGH);
    }

                 if(LEDcolor == "orange" || LEDcolor == "Orange"){
        analogWrite(redPin, 255);
        analogWrite(bluePin, 0);
        analogWrite(greenPin, 128);
    }

                     if(LEDcolor == "pink" || LEDcolor == "Pink"){
        analogWrite(redPin, 255);
        analogWrite(bluePin, 128);
        analogWrite(greenPin, 0);
    }
}