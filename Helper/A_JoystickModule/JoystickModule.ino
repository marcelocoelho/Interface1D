// Tutorial here: https://www.brainy-bits.com/arduino-joystick-tutorial/


#define INPUTX A0
#define INPUTY A1
#define INPUTSW A2


int sensorX = 0;    
int sensorY = 0;
int sensorSW = 0;

void setup() {

  Serial.begin(57600);
  pinMode(INPUTSW, INPUT); 
  digitalWrite(INPUTSW, HIGH);

}

void loop() {

  sensorX = analogRead(INPUTX);    
  sensorY = analogRead(INPUTY); 
  sensorSW = digitalRead(INPUTSW);
  
  // Notice that we are dividing sensor values by 4, so we can constrain them between 0 - 255 and make communication with Processing easier.
  
  Serial.print(sensorX/4);
  Serial.print("  ");
  Serial.print(sensorY/4);  
  Serial.print("   ");
  Serial.println(sensorSW); 
  
  
              
}
