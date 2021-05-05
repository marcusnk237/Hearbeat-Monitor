
//* Importation des bibliothèques*//
#define USE_ARDUINO_INTERRUPTS true 
#include <PulseSensorPlayground.h>        
//*******************************//

//*************************************************************** Variables ***************************************************************//
//* Entrée du capteur *//
const int PulseWire = 0;
//* LED qui s'allume lors de la détection d'un battement cardiaque *//       
const int HB = 13;   
//* Seuil à partir duquel on considère l'information comme un signal cardiaque (elle vaut 550 par défaut). Elle peut être modifiée  *//     
int Threshold = 550;    
//******************************************************************************************************************************************//

//************************************************** Initialisation **************************************************//
//* Creation d'une instance de détection de pulsation *//                              
PulseSensorPlayground pulseSensor;  

void setup() {   
  //* Initialisation du port série *//
  Serial.begin(9600);          
  //* Configuration du détecteur de pulsation *//
  pulseSensor.analogInput(PulseWire); 
  //* Initialisation de la LED *//  
  pulseSensor.blinkOnPulse(HB);    
  //* Initialisation du seuil *//
  pulseSensor.setThreshold(Threshold);  
  //* Envoi d'un message de démarrage après vérification *//
  if (pulseSensor.begin()) {
    Serial.println("Initialisation du moniteur cardiaque !");
  }
}
//********************************************************************************************************************//

//*********************** Programme principal ***********************//
void loop() {
  //* Récupération du nombre de battement par minute *//
  int myBPM = pulseSensor.getBeatsPerMinute();  
 //* Vérification de la détection d'un battement *//
  if (pulseSensor.sawStartOfBeat()) {             
    Serial.println("Battement detecte ! ");      
 //* Affichage de la valeur du battement sur le port série *// 
    Serial.print("BPM: ");                     
    Serial.println(myBPM);                        
}
  delay(20);
}
//******************************************************************//
