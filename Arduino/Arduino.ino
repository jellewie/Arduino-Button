/*
  Program written by JelleWho
*/
#include "Button.h"

//Button ButtonsA[2] = {buttons({11, 12}), buttons({13, 14})};
Button ButtonsA = buttons({26, LED_BUILTIN});

void setup() {
  Serial.begin(115200);
  attachInterrupt(ButtonsA.Data.PIN_Button, ISR_ButtonsA, CHANGE);  //Attack an interupt to the pin, so we can simply keep track of pushes
}
void loop() {
  Button_Time Value = ButtonsA.CheckButton();
  Serial.print(Value.StartPress);
  Serial.print("_");
  Serial.print(Value.Pressed);
  Serial.print(" L");
  Serial.print(Value.StartLongPress);
  Serial.print("_");
  Serial.print(Value.PressedLong);
  Serial.print(" D");
  Serial.print(Value.StartDoublePress);
  Serial.print(" R");
  Serial.print(Value.StartRelease);
  Serial.print(" ");
  
  Serial.print(Value.PressedTime);
  Serial.print(" ");
  Serial.println();
  delay(100);
}

//ISR must return nothing and take no arguments, so we need this sh*t
void ISR_ButtonsA() {
  ButtonsA.Pinchange();
}
