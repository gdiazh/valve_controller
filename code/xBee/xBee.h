#include "mbed.h"

/*typedef struct Tag{
    int packet[16];
    uint32_t id;
    float voltage_battery;
    float temperature;
    float signal_strength;
} Tag;*/

class xBee
{
    // Members
    Serial *device_;
    Serial *debug_port_;

public:
    // Members
    //Tag tag_;

    // Constructor
    xBee(Serial *rfid_port, Serial *debug_port) : 
        device_(rfid_port),
        debug_port_(debug_port)
        {}

    // Methods
    void setBaud(int baudrate);
    
    int readable();
    void read(void);
    void writeByte(uint8_t byte);
    void write(uint8_t *packet, uint8_t n);
    
    void sendPacket(uint8_t framehead, uint8_t code, uint8_t id);
    
    uint32_t checksum(uint8_t *packet, uint8_t n);

    void debugPrint(void);
};