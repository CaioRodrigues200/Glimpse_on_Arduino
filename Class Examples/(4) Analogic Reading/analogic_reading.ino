int delayTime = 500;
int pin13 = 13;
int P13voltage = 255; // Set the voltage between 5v & 0v (through 0 to 255)
int readGND = A0; // Ground voltage reading input
int readResistor = A1; // Resistor voltage reading input
float read_g; // Voltage readed from the ground pin (Not the actual voltage value)
float read_r; // Voltage readed from the resistor (Not the actual voltage value)
float Vg; // Actual voltage value from the ground pin
float Vr; // Actual voltage value from the resistor

void setup(){
pinMode(pin13,OUTPUT);
pinMode(readGND,INPUT);
pinMode(readResistor,INPUT);
Serial.begin(9600); // Setting the serial transference speed (baud rate)
}

void loop(){
 analogWrite(pin13,P13voltage); // Setting the average voltage comming from pin 13 (that means it isn't exactly the selected value, instead, an average based on multiple 5v and 0v steps)
 read_g = analogRead(readGND);
 read_r = analogRead(readResistor);
 Vg = (5./1023.)*read_g; // Value convertion
 Vr = (5./1023.)*read_r; // Value convertion
 Serial.print(Vg); 
 Serial.print(" ");
 Serial.println(Vr);
 delay(delayTime);
}