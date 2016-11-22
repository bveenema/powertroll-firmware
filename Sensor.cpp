#include "Sensor.h"

Sensor::Sensor(int16_t memAddress) {
  if(memAddress < 1) { // New Sensor
    _sensor_id = "FFFFFFFFFFFFFFFFFF";
    _publishRate = 60000;
  	_updateRate = 60000;
  	_currentData = random(10,100);
  	_hasNewData = true;
  	_lastDataTime = millis();
  	_isAlive = true;
  } else {
    // loadMem(memAddress);
  }
}

bool Sensor::checkForData(void) {
  return _hasNewData;
}

int32_t Sensor::getData(void) {
  return _currentData;
}

bool Sensor::checkHealth(void) {
  return _isAlive;
}

bool Sensor::publishData(int32_t data) {
  String publishString = String("{sID: " + String(_sensor_id) + ",data: " + String(data) + "}");
  bool returnVal = Particle.publish("data", publishString, PRIVATE);
  Serial.println("Publish Data");
  return returnVal;
}
bool Sensor::registerCloud(String sensor_id, String type, bool isWireless) {
  String publishString = String("{sID: " + String(sensor_id) + ",type: " + type + ",isWireless: " + String(isWireless) + "}");
  bool returnVal = Particle.publish("newSensor", publishString, PRIVATE);
  Serial.println("Register Cloud");
  return returnVal;
}

bool Sensor::recieveSettings(const char *id, uint32_t publishRate, uint32_t updateRate) {
  if(String(id).equals(String(_sensor_id))) {
    _publishRate = publishRate;
    _updateRate = updateRate;
    return true;
  }
  return false;
}
