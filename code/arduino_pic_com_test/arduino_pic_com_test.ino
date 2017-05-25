#include <SoftwareSerial.h>
SoftwareSerial PIC(7,8);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

uint8_t packet[5];

void debugPrint(void);
void readPIC(void);
void sendPacket(uint8_t framehead, uint8_t device_id, uint8_t valvula, uint8_t tiempo);
 
void setup()
{
  PIC.begin(115200);       // Inicializamos el puerto serie PIC que hemos creado
  Serial.begin(115200);   // Inicializamos  el puerto serie 
  for(int i=0;i<5;i++) packet[i] = 0;
}
 
void loop()
{
  // sendPacket(123, 240, 5, 6);
  // PIC.write(240);
  /*while(PIC.available())    // Si llega un dato por el puerto PIC se envía al monitor serial
  {
    Serial.println(PIC.read());
  }*/
  /*if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto PIC
  {
     PIC.write(Serial.read());
  }*/
  /*sendPacket(123, 240, 35, 26);
  readPIC();*/
  Serial.print(34);
  delay(50);
}

void readPIC(void)
{
    int i = 0;
    if (PIC.available())
    {
        // Serial.println("available");
        while (i < 5)
        {
            /*Serial.println("i:");
            Serial.println(i);*/
            delay(1);
            uint8_t byte = PIC.read();    //packets bytes
            packet[i++] = byte;
            // Serial.println(byte);
        }
        debugPrint();
    }
}

void debugPrint(void)
{
    Serial.println("PACKET from PIC");
    Serial.println("FORMAT: FHEAD ID N T CS");
    Serial.print("PACKET: ");
    for (uint8_t j=0;j<4;j++){
      Serial.print(packet[j]);
      Serial.print(",");
    }
    Serial.println(packet[4]);
    Serial.println("");
}

uint32_t checksum(uint8_t *packet, uint8_t n)
{
    uint32_t sum = 0;
    for (int j=0;j<n-1;j++) sum += packet[j];
    return sum;
}

void sendPacket(uint8_t framehead, uint8_t device_id, uint8_t valvula, uint8_t tiempo)
{
    uint8_t packet_len = 5;
    uint8_t out_packet[5];
    
     //Initialize
    for (int j=0;j<packet_len;j++) out_packet[j] = 0;
    
    //Build Packet
    out_packet[0] = framehead;   //Frame head
    out_packet[1] = device_id;   //Identify the controller
    out_packet[2] = valvula;     //Identify valve in the controller (0-3)
    out_packet[3] = tiempo;     //Aperture time for valve
    out_packet[4] = checksum(out_packet, packet_len) & 0x00FF; //Low byte of data checksum;
    
    //Send packet
    for (int j=0;j<packet_len;j++){
        PIC.write(out_packet[j]);
        // delay(5);
    }
}