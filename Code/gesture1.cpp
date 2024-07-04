#include <Wire.h>
#include "paj7620.h"

#define GES_REACTION_TIME 500
#define GES_ENTRY_TIME 800  
#define GES_QUIT_TIME 1000


void setup()
{
  uint8_t error = 0;


  Serial.begin(9600);
  Serial.println("\nPAJ7620U2 TEST DEMO: Recognize 9 gestures.");


  error = paj7620Init();
  if (error)
  {
    Serial.print("INIT ERROR,CODE:");
    Serial.println(error);
  }
  else
  {
    Serial.println("INIT OK");
  }
  Serial.println("Please input your gestures:\n");
}


void loop()
{
  uint8_t data = 0, data1 = 0, error;
  error = paj7620ReadReg(0x43, 1, &data);
  if (!error)
  {
    switch (data) 
    {
      case GES_RIGHT_FLAG:
        delay(GES_ENTRY_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if (data == GES_FORWARD_FLAG)
        {
          Serial.println("restroom");
          delay(GES_QUIT_TIME);
        }
        else if (data == GES_BACKWARD_FLAG)
        {
          Serial.println("food");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("snack");
        }
        break;
      case GES_LEFT_FLAG:
        delay(GES_ENTRY_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if (data == GES_FORWARD_FLAG)
        {
          Serial.println("Restroom");
          delay(GES_QUIT_TIME);
        }
        else if (data == GES_BACKWARD_FLAG)
        {
          Serial.println("food");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("water");
        }
        break;
      case GES_UP_FLAG:
        delay(GES_ENTRY_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if (data == GES_FORWARD_FLAG)
        {
          Serial.println("restroom");
          delay(GES_QUIT_TIME);
        }
        else if (data == GES_BACKWARD_FLAG)
        {
          Serial.println("food");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("Emergency");
        }
        break;
      case GES_DOWN_FLAG:
        delay(GES_ENTRY_TIME);
        paj7620ReadReg(0x43, 1, &data);
        if (data == GES_FORWARD_FLAG)
        {
          Serial.println("restroom");
          delay(GES_QUIT_TIME);
        }
        else if (data == GES_BACKWARD_FLAG)
        {
          Serial.println("food");
          delay(GES_QUIT_TIME);
        }
        else
        {
          Serial.println("relative call");
        }
        break;
      case GES_FORWARD_FLAG:
        Serial.println("restroom");
        delay(GES_QUIT_TIME);
        break;
      case GES_BACKWARD_FLAG:
        Serial.println("food");
        delay(GES_QUIT_TIME);
        break;
      case GES_CLOCKWISE_FLAG:
        Serial.println("Glucose empty");
        break;
      case GES_COUNT_CLOCKWISE_FLAG:
        Serial.println("Drousiness");
        break;
      default:
        paj7620ReadReg(0x44, 1, &data1);
        if (data1 == GES_WAVE_FLAG)
        {
          Serial.println("free time");
        }
        break;
    }
  }
  delay(100);
}