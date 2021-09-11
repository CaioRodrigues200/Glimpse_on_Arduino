#define tenPotPin A4
#define unitPotPin A5
#define buzzPin 9
#define confirmPin 6
#define redLedPin 4
#define greenLedPin 5

int precision_Ratio = 25; // Defines the percentage(%) between the right frequency interval 
                          // into the overall buzzer operation interval

int buzzer_Operation = 20; // Defines the buzzer operation interval

int TargetValue; // Reference value to seek for
int Delay = 2000; 
float uniPot_voltage, tenPot_voltage;
float unitPot_resValue, tenPot_resValue;
float tenPot_maxResistance = 10; // Ten unit potentiometer resistance (in Kilo-ohms)
float unitPot_maxResistance = 10; // Unit potentiometer resistance (in Kilo-ohms)
float diff; // Difference between confirmed and target values
unsigned int frequency = 0; // Sound frequency emitted by the buzzer
float fltFreq; // Variable created for data conversion

void setup(){
    Serial.begin(9600);

    pinMode(buzzPin, OUTPUT);
    pinMode(confirmPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);

    pinMode(unitPotPin, INPUT);
    pinMode(tenPotPin, INPUT);

    Serial.println("Insert a target value (between 0 and 110)");
    while(Serial.available()==0){}  
    TargetValue = Serial.parseInt();
}

void loop(){
    uniPot_voltage = analogRead(unitPotPin);
    unitPot_resValue = unitPot_maxResistance - ((10.0/1023.0) * uniPot_voltage); // Varies between 0 and 10

    tenPot_voltage = analogRead(tenPotPin);
    tenPot_resValue = tenPot_maxResistance - ((10.0/1023.0) * tenPot_voltage); // Varies between 0 and 10

    diff = TargetValue - (unitPot_resValue + tenPot_resValue*10);  // Varies between (in module) 0 and 110

    if(abs(diff) < buzzer_Operation){ // Buzzer operation interval
        fltFreq = 10000 - (abs(diff))*(8000/buzzer_Operation);
        frequency = (unsigned int) fltFreq; // Converts float to unsigned int
        tone(buzzPin, frequency);
    }
    else
        noTone(buzzPin);

    if(digitalRead(confirmPin) == HIGH){ // Confirmation proceedment 
        noTone(buzzPin);
        if(abs(diff) < (buzzer_Operation * precision_Ratio)/100 )
            digitalWrite(greenLedPin, HIGH);
        else
            digitalWrite(redLedPin, HIGH);

        delay(Delay);
        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, LOW);
    }
}