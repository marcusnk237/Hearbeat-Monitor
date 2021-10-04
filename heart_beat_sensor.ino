
//* Loading libraries *//
#define USE_ARDUINO_INTERRUPTS true 
#include <PulseSensorPlayground.h>        
//*******************************//

//*************************************************************** Variables ***************************************************************//
//* Entrée du capteur *//
const int PulseWire = 0;
//* A LED connect to this pin will light on each time a heartbeat is detect *//       
const int HB = 13;   
//* If the signal if above this threshold, we consider it as a ECG Signal *//     
int Threshold = 550;    
//******************************************************************************************************************************************//

//************************************************** Initialization **************************************************//
//* Creation of a pulse sensor instance *//                              
PulseSensorPlayground pulseSensor;  

void setup() {   
  //* Initialization of serial port  *//
  Serial.begin(9600);          
  //* Configuration of the pulse sensor *//
  pulseSensor.analogInput(PulseWire); 
  //* Initialization of the  LED *//  
  pulseSensor.blinkOnPulse(HB);    
  //* Initialization of the threshold *//
  pulseSensor.setThreshold(Threshold);  

  if (pulseSensor.begin()) {
    Serial.println("Heartbeat monitor initialization !");
  }
}
//********************************************************************************************************************//

//*********************** Main program ***********************//
void loop() {
  //* Get heartbeat per minute*//
  int myBPM = pulseSensor.getBeatsPerMinute();  
 //* Check if a heartbeat is detect *//
  if (pulseSensor.sawStartOfBeat()) {             
    Serial.println("Heartbeat detect ! ");      
 //* Display value *// 
    Serial.print("BPM: ");                     
    Serial.println(myBPM);                        
}
  delay(20);
}
//******************************************************************//
