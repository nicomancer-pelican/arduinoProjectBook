int switchState = 0;

void setup() {
  // set whether the digital pins are inputs or outputs
  // pin 2 is pusher button input, pins 3,4,5 are outputs to LEDs
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  
}

void loop() {
  // check voltage of pin 2
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // the button is not pressed so turn on green LED and turn off red LEDS
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    // button is pressed so turn off green LED and turn on red LEDS blinking
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    //make lights blink to look extra cool
    delay(250);   // 250 ms delay
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }
  
}
