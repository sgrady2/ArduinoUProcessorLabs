/* 
   Lab 2, example 2
   This code is *partially* complete. Follow the comments in the code to complete
   this program.
*/ 
const int ledPin = 13;            // choose the pin for the LED 
const int inputPin = 7;           // choose the input pin (for a pushbutton)

const int led1 = 3;      // We add these 
const int led2 = 4;
const int led3 = 5;    // Add code for Arduino pins 5 and 6 to be assigned
const int led4 = 6;                        // to the variables led3 and led4 like the 2 lines of code above

int val = 0;         // place to save input value of switch
int countVal = 0;    // this is where we will store our count value.
                     // Notice we do not use "const" because this value
                     // will change

int valPrev = LOW;  // Test previous value with current value on switch
                    // to detect switch change state

void setup() { 
  pinMode(ledPin, OUTPUT);         // declare LED as output 
  pinMode(inputPin, INPUT);        // declare pushbutton as input 
  
  pinMode(led1, OUTPUT);         // declare led1 as output 
  pinMode(led2, OUTPUT);         // declare led2 as output
  pinMode(led3, OUTPUT);                               // Do the same for led3 and led4 here. 
  pinMode(led4, OUTPUT);
} 

void loop(){ 
// Clear all display LEDs
  digitalWrite(led1, LOW);
                          // Do the same for LEDs 2,3,and4 here
  
// Turn on correct Display LED according to countVal
  switch(countVal) 
    { 
      case 0:
        break;  // no need to turn LEDs on
      case 1:
        digitalWrite(led1, HIGH);  // if count is 1, turn on led1
        break;
      case 2:
        digitalWrite(led2, HIGH); // if count is 2, turn on led2
        break;
      case 3:
        digitalWrite(led3, HIGH);            // add code to turn on LED 3
        break;
      case 4:
        digitalWrite(led4, HIGH);           // add code to turn on LED 4
        break;
      default:
        countVal = 0;  // Incase countVal for some reason is not in expected
        break;         // range, set to 0. We should never get here, but
    }                  // you ALWAYS set a default case to be safe
  
  val = digitalRead(inputPin);    // read input value 
  delay(5);                       // DEBOUNCE the switch (5ms is fine)
  
  if (val == HIGH)   // check if the input is HIGH 
  { 
   digitalWrite(ledPin, HIGH);     // turn LED on if switch is pressed
   if (valPrev == LOW)
     countVal++;                 // increment countVal by one only if Switch
                                 // changes state, notice no braces needed
                                 // for 1-line if statement
   countVal = countVal % 5;      // mod value to loop from 0 to 4
   valPrev = HIGH;               // set valPrev to 1 or HIGH
  } 
  else 
  { 
    valPrev = LOW;                  // set valPrev to 0 or LOW
  } 
  
} 

