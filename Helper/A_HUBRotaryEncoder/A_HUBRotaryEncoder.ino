


// Hardware setup:
// Attach a rotary encoder with output pins to A0 and A1.
// The common contact should be attached to ground.

#include <Wire.h>

#include <RotaryEncoder.h>

// Setup a RoraryEncoder for pins A0 and A1:
RotaryEncoder encoder(A0, A1);

void setup()
{
  Serial.begin(57600);
  Serial.println("Serial Ready");

 // Join I2C bus as slave with address 8
  Wire.begin(0x08);
  Wire.onRequest(requestEvent);
  Serial.println("i2c Ready");

  
} 

// declaring this outside of the loop so we can read from request event
static int pos = 0;
int newPos = 0;

// Read the current position of the encoder and print out when changed.
void loop()
{
  
  encoder.tick();

  newPos = encoder.getPosition();
  Serial.println(newPos);
  /*if (pos != newPos) {
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
  } */
} 


// THIS IS THE CODE THAT ASKS THE HUB IF IT CAN TRANSMIT
void requestEvent() {

  /* THIS SENDS RANDOM NUMBER TO HUB IN CASE YOU NEED TO TEST THE CONNECTION
  int randNumber = random(1,99);
  writeData(randNumber);
  */

  if (pos != newPos) {
    //Serial.println(newPos); // transmit over serial to debuf
    writeData(pos);           // transmit to hub
    pos = newPos;
  } 

  
 
  Serial.println("request received");
}

// THIS PACKAGES AND TRANSMITS DATA TO HUB
void writeData(char newData) {
  char data[] = {5, newData};
  int dataSize = sizeof(data);
  Wire.write(data, dataSize);
}
