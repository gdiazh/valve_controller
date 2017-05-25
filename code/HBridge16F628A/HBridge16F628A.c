/*
 * File:   HBridge16F628A.c
 * Author: Gustavo Hernan Díaz Huenupan
 *
 * Created on April 15, 2017, 23:56 PM
 */

#include "configBits.h"
#include "HBridge.h"

void main(void) {
  hbridgeInit();
  while(1)
  {
    openValveA();
    openValveB();
    closeValveA();
    closeValveB();
    __delay_ms(1000);
  }
}