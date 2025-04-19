#define TRIG_PIN 5
#define ECHO_PIN 18
#define SOUND_SENSOR_PIN 34  // Analog pin

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  float distance = getDistanceCM();
  int soundLevel = analogRead(SOUND_SENSOR_PIN); // 0 to 4095 on ESP32

  Serial.print("Distance (cm): ");
  Serial.print(distance);
  Serial.print(" | Sound Level: ");
  Serial.println(soundLevel);

  delay(300);
}