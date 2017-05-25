/**
 * @brief Arduino Driver v1.0 for a Valve Controller
 */
 
// Author: Gustavo Diaz

// Requiered Libraries
// #include <HBridge_754410.h>
#include "ValvePair.h"

// Output pins for HBridge control
#define CTL1A 3
#define CTL2A 4
#define CTL1B 5
#define CTL2B 6

// Device Control Handler
HBridge hbridge1(CTL1A, CTL2A, CTL1B, CTL2B);
ValvePair valves_pair1(&hbridge1);

void setup()
{
	//Init Serial port
	Serial.begin(115200);

  //Start Program
  Serial.println("Setup ready");
  valves_pair1.close();
}

void loop()
{
  // Serial open/close
  valves_pair1.valveA.open();
  valves_pair1.valveB.open();
  valves_pair1.valveA.close();
  valves_pair1.valveB.close();
  delay(2000);
  // Parallel open/close
  valves_pair1.open();
  delay(1000); //keep open both valves for 1[s]
  valves_pair1.close();
  // wait 1[s] to repeat tests
  delay(1000);
}