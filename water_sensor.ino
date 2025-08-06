#define TDS_PIN A0
#define PH_PIN A1
#define RELAY_PIN 7

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  int tdsValue = analogRead(TDS_PIN);
  int phValue = analogRead(PH_PIN);

  float voltage = tdsValue * (5.0 / 1023.0);
  float ph = phValue * (14.0 / 1023.0);

  Serial.print("TDS: ");
  Serial.print(tdsValue);
  Serial.print(" | pH: ");
  Serial.println(ph);

  // Simple logic to activate purification if pH is bad
  if (ph < 6.5 || ph > 8.5) {
    digitalWrite(RELAY_PIN, HIGH);  // Pump ON
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Pump OFF
  }

  delay(2000);
}
