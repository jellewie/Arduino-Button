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
  Button_Time Value = ButtonsA.CheckButton();   //Get/update the button state

  /* Print all state values to serial for debugging */
  Serial.print(Value.StartPress);
  Serial.print("_");
  Serial.print(Value.Pressed);
  Serial.print(" L");
  Serial.print(Value.StartLongPress);
  Serial.print("_");
  Serial.print(Value.PressedLong);
  Serial.print(" D");
  Serial.print(Value.StartDoublePress);
  Serial.print("_");
  Serial.print(Value.DoublePress);
  Serial.print(" R");
  Serial.print(Value.StartRelease);
  Serial.print("_");
  Serial.print(Value.PressEnded);
  Serial.print(" ");
  Serial.print(Value.PressedTime);
  Serial.print(" ");
  Serial.println();

  delay(100);             //Just some time to make sure so humans can read the serial a bit better (Yes I know delays are bad)

  /* Just some more examples of how to use it */
  if (Value.StartPress) {
    Serial.println("The button is just pressed");
  }
  if (Value.StartLongPress) {
    Serial.println("The button is just pressed for a long time");
  }
  if (Value.StartDoublePress) {
    Serial.println("The button is just double pressed");
  }
  if (Value.StartRelease) {
    Serial.println("The button has just been released");
  }
}

/* ISR must return nothing and take no arguments, so we need this sh*t */
void ISR_ButtonsA() {
  ButtonsA.Pinchange();
}
