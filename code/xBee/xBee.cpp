#include "xBee.h"

void xBee::setBaud(int baudrate)
{
    device_->baud(baudrate);
}

int xBee::readable()
{
    int rc = device_->readable();
    return rc;
}

void xBee::read(void)
{
    int byte = 0;
    if (device_->readable())
    {
        byte = device_->getc();    //packet bytes
        debug_port_->printf("Received from Xbee: %x\n", byte);
        //return byte;
    }
    //return byte;
}

void xBee::writeByte(uint8_t byte)
{
    device_->putc(byte);
}    

void xBee::write(uint8_t *packet, uint8_t n)
{
    //device_->putc(data);
    for (int j=0;j<n;j++){
        //device_->putc(packet[j]);
        device_->printf("%d", packet[j]);
        device_->putc(':');
    }
    device_->putc('\n');
}

void xBee::sendPacket(uint8_t framehead, uint8_t code, uint8_t id)
{
    uint8_t packet_len = 4;
    uint8_t out_packet[packet_len];
    
     //Initialize
    for (int j=0;j<packet_len;j++) out_packet[j] = 0;
    
    //Build Packet
    out_packet[0] = framehead;   //Frame head
    out_packet[1] = code;        //255 for a "send id msg", 254 for "alert msg"
    out_packet[2] = id;          //id received
    out_packet[3] = checksum(out_packet, packet_len) & 0x00FF; //Low byte of data checksum;
    
    debug_port_->printf("SENDING PACKET ...\n");
    debug_port_->printf("FORMAT: FHEAD CODE ID CHECKSUM\n");
    debug_port_->printf("PACKET: ");
    for (int j=0;j<packet_len;j++) debug_port_->printf("%d,", out_packet[j]);
    debug_port_->printf("\n\n");
    write(out_packet, packet_len);
}

uint32_t xBee::checksum(uint8_t *packet, uint8_t n)
{
    uint32_t sum = 0;
    for (int j=0;j<n-1;j++) sum += packet[j];
    return sum;
}

void xBee::debugPrint(void)
{
    debug_port_->printf("RFID Detected\n");
    /*debug_port_->printf("FORMAT: FHEAD UI UI ID3 ID2 ID1 ID0 S V R1 R2 T1 T2 TS SIG CS\n");
    debug_port_->printf("PACKET: ");
    for (int j=0;j<15;j++) debug_port_->printf("%d,", tag_.packet[j]);
    debug_port_->printf("%d", tag_.packet[15]);
    debug_port_->printf("\n");*/
}

/*
Serial pc_port(USBTX, USBRX);
Serial xbee_port(p28, p27);

xBee xbee(&xbee_port, &pc_port);

int main()
{
    xbee.init();
    xbee.setBaud(38400);   //[bps]
    while(1){
        xbee.read();
        xbee.debugPrint();
    }
    return 0;
}*/