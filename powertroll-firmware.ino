#include "application.h"
#include "Sensor.h"
#include "sensitive_info.h"
#define led D7  // The on-board LED

//Sysem Settings
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

Sensor sensor = Sensor();

void setup() {
  Serial.begin(11520);
  delay(500);
  Particle.connect();
  pinMode(led, OUTPUT);

  Serial.println("Alive");
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  String temp = String(random(60, 80));
  // Particle.publish("temp", temp, PRIVATE);
  uint32_t tempInt = temp.toInt();
  sensor.publishData(tempInt);
  sensor.registerCloud("12345", "foo", true);
  Serial.printlnf("user: %s", user_id);
  delay(58000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(2000);               // Wait for 30 seconds
}
