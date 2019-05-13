// I release this code is in the public domain, remix, use, profit etc 

#include <Bounce.h>

Bounce button0 = Bounce(5, 15); // D6 pushbuttons 1-4
Bounce button1 = Bounce(6, 15);
Bounce button2 = Bounce(7, 15);
Bounce button3 = Bounce(8, 15);

Bounce button4 = Bounce(1, 15); // SPDT1
Bounce button5 = Bounce(2, 15); // SPDT2

float knob_A1;
float knob_A2;
float knob_A3;
float knob_A4;
float knob_A5;
float knob_A6;

const int led1 = 10;
const int led2 = 4;
const int led3 = 3;
const int led4 = 12;

void setup() 
{
  Serial.begin(9600);
  pinMode(5, INPUT_PULLUP); // Turn on pullups in the Teensy otherwise buttons won't work
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  delay(300);
  Serial.println("Proto Shield Simple Tester");
}

void loop() 
{
  readButtons(); // Read all buttons and switches, turns on/off leds
  readPots(); // Prints pot values 
}

void readButtons()
{
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();

    if (button0.risingEdge())
   {
    digitalWrite(led1, LOW);
    Serial.println("Button 0 UnPressed");
   }

   if (button0.fallingEdge())
   {
    digitalWrite(led1, HIGH);
    Serial.println("Button 0 Pressed");
   }

    if (button1.risingEdge())
   {
    digitalWrite(led2, LOW);
    Serial.println("Button 1 UnPressed");
   }

   if (button1.fallingEdge())
   {
    digitalWrite(led2, HIGH);
    Serial.println("Button 1 Pressed");
   }

    if (button2.risingEdge())
   {
    digitalWrite(led3, LOW);
    Serial.println("Button 2 UnPressed");
   }

   if (button2.fallingEdge())
   {
    digitalWrite(led3, HIGH);
    Serial.println("Button 2 Pressed");
   }

    if (button3.risingEdge())
   {
    digitalWrite(led4, LOW);
    Serial.println("Button 3 UnPressed");
   }

   if (button3.fallingEdge())
   {
    digitalWrite(led4, HIGH);
    Serial.println("Button 3 Pressed");
   }

    if (button4.risingEdge())
   {
    Serial.println("SPDT2 ON");
   }

   if (button4.fallingEdge())
   {
    Serial.println("SPDT2 OFF");
   }

    if (button5.risingEdge())
   {
    Serial.println("SPDT2 OFF");
   }

   if (button5.fallingEdge())
   {
    Serial.println("SPDT2 ON");
   }
}

void readPots()
{
  
  knob_A1 = (float)analogRead(14) / 1024.0; // pin14
  knob_A2 = (float)analogRead(15) / 1024.0; // pin 15
 
  knob_A3 = (float)analogRead(21) / 1024.0; // VR1
  knob_A4 = (float)analogRead(20) / 1024.0; // VR2

  knob_A5 = (float)analogRead(16) / 1024.0; // VR3
  knob_A6 = (float)analogRead(17) / 1024.0; // VR4

//  Serial.print("knob 1: ");
//  Serial.print (knob_A1);
//  Serial.print("knob 2: ");
//  Serial.print (knob_A2);
//
//  Serial.print("knob 3: ");
//  Serial.print (knob_A3);
//  Serial.print("knob 4: ");
//  Serial.print (knob_A4);
//
//  Serial.print("knob 5: ");
//  Serial.print (knob_A5);
//  Serial.print("knob 6: ");
//  Serial.println (knob_A6);
}
