/*
  Program written by JelleWho https://github.com/jellewie
*/

//Define thesesettings to change/apply things in Button.h
#define Button_SerialEnabled                            //Disable to not send Serial debug feedback
//#define Time_StartLongPressMS 3000                      //After howmuch Ms we should consider a press a long press
//#define Time_ESPrestartMS 15000                         //After howmuch Ms we should restart the ESP, note this is only triggered on released, or on a CheckButtons() call
//#define Time_StartDoublePress 200                       //Withing howmuch Ms of the last release should the button be pressed for it to be a double press?
//#define Time_RejectStarts 80                            //Just some rejection

#include "Button/Button.h"                              //https://github.com/jellewie/Arduino-Button

Button ButtonsA = buttons({26, LED_BUILTIN});
//Button ButtonsA[2] = {buttons({11, 12}), buttons({13, 14})};  //Example of declairing an array of buttons, This also sets the pinmode to 'INPUT/OUTPUT'

void setup() {
  Serial.begin(115200);                                 //Since we defided we want serial feedback, we should start Serial at the desired speed
  attachInterrupt(ButtonsA.Data.PIN_Button, ISR_ButtonsA, CHANGE);  //Attack an interupt to the pin, so we can simply keep track of pushes
}
void loop() {
  Button_Time Value = ButtonsA.CheckButton();           //Get the button state

  //All triggers are defined in '/Button/Button.h' in 'struct Button_Time {x}'
  //Examples of how to use a few of these triggers:
  if (Value.StartPress)
    Serial.println("The button is just pressed");

  if (Value.StartLongPress)
    Serial.println("The button is just pressed for a long time");

  if (Value.StartDoublePress)
    Serial.println("The button is just double pressed");

  if (Value.StartRelease)
    Serial.println("The button has just been released");

  delay(250);                                           //Some time to make sure the humans can read the serial a bit better (Yes I know delays are really bad)
}

/* ISR must return nothing and take no arguments, so we need this sh*t */
void ISR_ButtonsA() {
  ButtonsA.Pinchange();
}
