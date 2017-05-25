/**
 * @brief Cube Manager Device Library
 */

// Author: Gustavo Diaz

// Requiered Libraries
#include <Arduino.h>

// Output pins for HBridge control
// #define ctl1A 4
// #define ctl2A 5

/**
 * @class HBridge
 * @brief Class for test aplication with H-Bridge SN754410
 */

class HBridge
{
    // Members
    // port A
    uint8_t ctl1A_; // 1A (pin 2) on SN754410
    uint8_t ctl2A_; // 2A (pin 7) on SN754410
    // port B
    uint8_t ctl1B_; // 3A (pin 10) on SN754410
    uint8_t ctl2B_; // 4A (pin 15) on SN754410

    // HardwareSerial *debug_port_;

public:
    // Public Members

    // constructor de base (null)
    HBridge() {}

    // constructror parametrizado
    HBridge(uint8_t ctl1A, uint8_t ctl2A, uint8_t ctl1B, uint8_t ctl2B):
        ctl1A_(ctl1A),
        ctl2A_(ctl2A),
        ctl1B_(ctl1B),
        ctl2B_(ctl2B)
        // debug_port_(debug_port)
    {
        // Config pins
        pinMode(ctl1A_, OUTPUT);
        pinMode(ctl2A_, OUTPUT);
        pinMode(ctl1B_, OUTPUT);
        pinMode(ctl2B_, OUTPUT);
    }

    // methods
    void portA_LL();
    void portA_LH();
    void portA_HH();
    void portA_HL();

    void portB_LL();
    void portB_LH();
    void portB_HH();
    void portB_HL();

// private:
    // methods
    
};