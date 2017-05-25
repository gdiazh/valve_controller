/**
 * @brief Arduino Driver v1.0 for HBridge aplication
 */
 
// Author: Gustavo Diaz

// Requiered Libraries
#include "puente_h.h"

// Output pins for HBridge control
#define CTL1A 3
#define CTL2A 4
#define CTL1B 5
#define CTL2B 6

// SoftwareSerial Bluetooth(7,8);    // RX, TX Arduino PINs, conected to Bluetooth

// Device Control Handler
HBridge hbridge(CTL1A, CTL2A, CTL1B, CTL2B);

void setup()
{
	//Init Serial port
	Serial.begin(115200);
  // Bluetooth.begin(115200);

  //Start Program
  Serial.println("Setup ready");
}

void loop()
{
  hbridge.portA_LL();
  hbridge.portB_LL();
  delay(1000);
  hbridge.portA_LH();
  hbridge.portB_LH();
  delay(1000);
  hbridge.portA_HL();
  hbridge.portB_HL();
  delay(1000);
  hbridge.portA_HH();
  hbridge.portB_HH();
  delay(1000);
}