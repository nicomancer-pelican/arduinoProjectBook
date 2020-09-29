const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  // open a serial port
  Serial.begin(9600);   // 9600 bits per second

  // set pin outputs
  for (int pinNumber = 2; pinNumber <5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // get value from sensor
  int sensorVal = analogRead(sensorPin);

  // print to serial monitor
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  // print to serial monitor
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convert voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  
  // print to serial monitor
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  // light up LEDs on temperature reading
  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if ((temperature >= baselineTemp + 2) && (temperature < baselineTemp + 4)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if ((temperature >= baselineTemp + 4) && (temperature < baselineTemp + 6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  // analog to digital converter needs a bit of time so small delay to smooth out
  delay(1000);
}
