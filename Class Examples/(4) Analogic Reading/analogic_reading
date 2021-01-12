int delayTime = 500;
int pin13 = 13;
int P13voltage = 255; // Set the voltage between 5v & 0v (through 0 to 255)
int readAll = A0; // Circuit voltage reading input
int readResistor = A1; // Resistor voltage reading input
float read0; // Voltage readed from the whole circuit (Not the actual voltage value)
float read1; // Voltage readed from the resistor (Not the actual voltage value)
float V0; // Actual voltage value from the whole circuit
float V1; // Actual voltage value from the resistor

void setup(){
pinMode(pin13,OUTPUT);
pinMode(readAll,INPUT);
pinMode(readResistor,INPUT);
Serial.begin(9600); // Setting the serial transference speed (baud rate)
}

void loop(){
 analogWrite(pin13,P13voltage); // Setting the average voltage comming from pin 13 (that means it isn't exactly the selected value, instead, an average based on multiple 5v and 0v steps)
 read0 = analogRead(readAll);
 read1 = analogRead(readResistor);
 V0 = (5./1023.)*read0; // Value convertion
 V1 = (5./1023.)*read1; // Value convertion
 Serial.print(V0); 
 Serial.print(" ");
 Serial.println(V1);
 delay(delayTime);
}