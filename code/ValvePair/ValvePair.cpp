/**
 * @brief Class to Controll 2 latch valves with HBridge
 */
 
// Author: Gustavo Diaz

#include "ValvePair.h"

void Valve::open(void)
{
    if (port_ == 'A')
    {
        hbridge_->portA_LH();
        delay(OPEN_TIME);
        hbridge_->portA_LL();
    }
    else if (port_ == 'B')
    {
        hbridge_->portB_LH();
        delay(OPEN_TIME);
        hbridge_->portB_LL();
    }
}

void Valve::close(void)
{
    if (port_ == 'A')
    {
        hbridge_->portA_HL();
        delay(CLOSE_TIME);
        hbridge_->portA_LL();
    }
    else if (port_ == 'B')
    {
        hbridge_->portB_HL();
        delay(CLOSE_TIME);
        hbridge_->portB_LL();
    }
}

// Open both valves on HBridge
void ValvePair::open(void)
{
	hbridge_->portA_LH();
	hbridge_->portB_LH();
	delay(OPEN_TIME);
	hbridge_->portA_LL();
	hbridge_->portB_LL();
}

void ValvePair::close(void)
{
	hbridge_->portA_HL();
	hbridge_->portB_HL();
	delay(CLOSE_TIME);
	hbridge_->portA_LL();
	hbridge_->portB_LL();
}