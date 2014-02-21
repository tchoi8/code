/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 9 to ground 
 * pushbutton attached to pin 2 from Ground
 
 

 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 modified by KOBAKANT for the WishLab workshop
 http://www.kobakant.at/DIY/?p=4967
 
*/

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  9;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int delayAmount=30;
int fadeAmount=5;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input and turn on the pull up resister:
  pinMode(buttonPin, INPUT_PULLUP);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
  // fade in from min to max in increments of fadeAmount:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeAmount) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for delayAmount milliseconds to see the dimming effect    
    delay(delayAmount);                            
  } 

  // fade out from max to min in increments of fadeAmount:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeAmount) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for delayAmount milliseconds to see the dimming effect    
    delay(delayAmount);                            
  } 
  else {
    // turn LED off:
    analogWrite(ledPin, 0); 
    fadeValue = 0;
  }
}
