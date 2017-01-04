#include "application.h"
#include "pins010317.h"
#include "Sensor.h"
#include "sensitive_info.h"
#include "cloud_functions.h"
#include <vector>
#define led D7  // The on-board LED

//Sysem Settings
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

std::vector<Sensor> sensors;

void setup() {
  // Random Seed work-around
  uint32_t seed = HAL_RNG_GetRandomNumber();
  srand(seed);

  Serial.begin(115200);
  delay(500);
  while(!Serial.available()) Particle.process();

  Particle.connect();
  waitFor(Particle.connected, 30000);
  delay(1000);
  sensors.push_back(Sensor(0));
  sensors.push_back(Sensor(0));
  sensors.push_back(Sensor(0));
  cloud_functions_Register();
  pinMode(led, OUTPUT);

  Serial.println("Alive");
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED
  uint32_t tempInt = random(60, 80);
  sensors[0].publishData(tempInt);
  sensors[0].registerCloud("12345", "foo", true);
  Serial.printlnf("user: %s", sensitive_info_user_id);
  delay(58000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(2000);               // Wait for 30 seconds
}
