# Arduino-Button
 A library kind of way to simply use a button with multiple triggers in Arduino, an example is included
 Multiple buttons can be used. Also due to interrupts being used, button pressed cannot be lost.
 
 Just simple get and save the value with 'CheckButton()'
 and then simple use '.StartPress' or 'StartDoublePress' to do some actions

# How to use
1. Add file to Arduino sketch folder and include it in your sketch with *'#include "Button.h"'*
2. Declair a button with *'Button YourVairableName = buttons({PinOfTheButton, SomeValue});'* for your convenience I’ve included another variable, this could be used for a LED to attack to it, so you can simply use the pin to have button feedback
3. attach the interrupt to the pin *'attachInterrupt(YourVairableName.Data.PIN_Button, FunctionToCall, CHANGE);'*
4. add a function to have the interrupt point to (yes I know this sounds stupid, but Arduino doesn’t allow you to do so any other way) *'void FunctionToCall () {YourVairableName.Pinchange();}'*

# Function definition
- **.StartPress**

This is triggered once when the button is pressed (these flags will only reset after you called the function, so you won’t lose a press)

- **.Pressed**

This is the current state of the button 

- **.StartLongPress**

This is triggered once when the button is pressed longer than 'Time_StartLongPressMS'||'5000' ms

- **.PressedLong**

This is the current state of the button but only true if it's pressed longer than 'Time_StartLongPressMS'||'5000' ms

- **.StartDoublePress**

This is triggered once when a new button pressed is faster than 'Time_StartDoublePress'||'250' ms ago

- **.StartRelease**

This is triggered once when a button is released

