int frequency = 5;//Гц
int period = 1000/frequency;
byte pin = LED_BUILTIN;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  Serial.println("Период: "+String(period)+"мс");
  pinMode(pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(period/2);                      // wait for a second
  digitalWrite(pin, LOW);   // turn the LED off by making the voltage LOW
  delay(period/2);                      // wait for a second
}
