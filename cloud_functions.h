#include "application.h"
#include <vector>

extern std::vector<Sensor> sensors;

int updateSensor(String update);

bool cloud_functions_Register(void) {
  bool cf1 = Particle.function("updateSensor", updateSensor); // {{id: String}},{{publishRate: Number"}},{{updateRate: Number}}
  Serial.printlnf("Registered updateSensor: %u", cf1);

  return 0;
}

int updateSensor(String update) {
  bool updatedASensor = 0;
  // Decipher update String {{id: String}},{{publishRate: Number"}},{{updateRate: Number}}
    char id [18];
    uint32_t publishRate = 0;
    uint32_t updateRate = 0;
    sscanf( update, "%18s,%u,%u", &id, &publishRate, &updateRate );

  for(uint8_t i = 0; i < sensors.size(); i++) {
    bool isMatchingId = sensors[i].recieveSettings(id, publishRate, updateRate);
    if(isMatchingId) {
      updatedASensor = 1;
    }
  }
  return (int)updatedASensor;
}
