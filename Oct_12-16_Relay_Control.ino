/*
Sketch Oct_12-16 Relay Control test.
 Turn on LED from pin 13 when K1 is turned on, K2 will be off.
 Wait 500 (1/2 second) 
 Turn off LED and K1 when K2 is turned on.
 Wait 500 (1/2 second)
 Repeat
*/
 const int ledPin = 13; // LED light on the Arduino
 const int K1Pin  = 8;  // K1 triggers on pin 8 LOW
 const int K2Pin  = 9;  // K2 triggers on pin 9 LOW
 
void setup() {
 pinMode (ledPin, OUTPUT); // Set up the digital outputs
 pinMode (K1Pin, OUTPUT);
 pinMode (K2Pin, OUTPUT);
}

void loop() {
 for (int x=0; x < 10; x++)   // Do the Relay test 10 times
      // This statement does 3 things: declares an integer x and sets the 
      // initial value to 0, tests to see if x is less than 10, then
      // increments the value of x before processing the statements 
      // between the braces below.  Every other pass through will 
      // test the value of x and terminate if it fails, then increments x
 {
 digitalWrite (ledPin, HIGH); // Turn on the LED
 digitalWrite (K1Pin, LOW);   // Turn on the K1 Relay
 digitalWrite (K2Pin, HIGH);  // Turn off the K2 Relay
 delay (500);                 // Pause 1/2 second
 digitalWrite (ledPin, LOW);  // Turn off the LED
 digitalWrite (K1Pin, HIGH);  // Turn off the K1 Relay
 digitalWrite (K2Pin, LOW);   // Turn on the K2 Relay
 delay (500);                 // Pause 1/2 second
 }
 digitalWrite (K2Pin, HIGH);  // Turn off the K2 Relay 
 while (1) {}                 // "Stop" the program by doing nothing
}
