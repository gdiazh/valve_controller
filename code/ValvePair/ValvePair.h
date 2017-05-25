/**
 * @brief Class to Controll 2 latch valves with HBridge
 */

// Author: Gustavo Diaz

// Requiered Libraries
#include <Arduino.h>
#include <HBridge_754410.h>

#define OPEN_TIME 1000      //[ms]
#define CLOSE_TIME 1000     //[ms]

class Valve
{
    // Members
    char port_;
    HBridge *hbridge_;

public:
    // Public Members

    // constructor de base (null)
    Valve() {}

    // constructror parametrizado
    Valve(HBridge *hbridge, char port):
        hbridge_(hbridge),
        port_(port)
    {
        //init vars
    }

    // methods
    void open(void);
    void close(void);

// private:
    // methods
};

class ValvePair
{
    // Members
    /*char portA_;
    char portB_;*/
    HBridge *hbridge_;

public:
    // Public Members
    Valve valveA;
    Valve valveB;

    // constructor de base (null)
    ValvePair() {}

    // constructror parametrizado
    ValvePair(HBridge *hbridge):
        hbridge_(hbridge),
        valveA(hbridge, 'A'),
        valveB(hbridge, 'B')
    {
        //init vars
    }

    // methods
    void open(void);
    void close(void);

// private:
    // methods
};
