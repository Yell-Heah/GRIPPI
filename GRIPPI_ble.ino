/*
  using https://github.com/T-vK/ESP32-BLE-Mouse
*/
#include <BleMouse.h>
BleMouse bleMouse;


int xMove = 0; //x coordinate
int yMove = 0; //y coordinate
      
void setup() 
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void loop() 
{
  if (bleMouse.isConnected()) 
  {
    // check if data is available
    if (Serial.available() > 0) 
    {
      // read the incoming data:
      xMove = Serial.parseInt();
      yMove = Serial.parseInt();
      
//      bleMouse.move(xMove, yMove, 0);
      for (int i=0; i<=10; i++)
      {
        bleMouse.move(xMove/10, yMove/10, 0);
      }

      // prints the received data
      Serial.print("Received: ");
      Serial.println(xMove);
      Serial.println(yMove);
    }
  }
  delay(50);
}
