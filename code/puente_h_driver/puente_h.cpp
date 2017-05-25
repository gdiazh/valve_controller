/**
 * @brief Simple test H-Bridge aplication
 */
 
// Author: Gustavo Diaz

#include "puente_h.h"

void HBridge::portA_LL(void)
{
	digitalWrite(ctl1A_, LOW);
	digitalWrite(ctl2A_, LOW);
}

void HBridge::portA_LH(void)
{
	digitalWrite(ctl1A_, LOW);
	digitalWrite(ctl2A_, HIGH);
}

void HBridge::portA_HL(void)
{
	digitalWrite(ctl1A_, HIGH);
	digitalWrite(ctl2A_, LOW);
}

void HBridge::portA_HH(void)
{
	digitalWrite(ctl1A_, HIGH);
	digitalWrite(ctl2A_, HIGH);
}

void HBridge::portB_LL(void)
{
	digitalWrite(ctl1B_, LOW);
	digitalWrite(ctl2B_, LOW);
}

void HBridge::portB_LH(void)
{
	digitalWrite(ctl1B_, LOW);
	digitalWrite(ctl2B_, HIGH);
}

void HBridge::portB_HL(void)
{
	digitalWrite(ctl1B_, HIGH);
	digitalWrite(ctl2B_, LOW);
}

void HBridge::portB_HH(void)
{
	digitalWrite(ctl1B_, HIGH);
	digitalWrite(ctl2B_, HIGH);
}

/*void HBridge::printVariables(void)
{
    debug_port_->print("some_var");
    debug_port_->print(";");
}*/