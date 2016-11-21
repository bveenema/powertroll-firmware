#include "Sensor.h"

Sensor::Sensor(void) {
  _publishRate = 60000;
  _sensor_id = "FFFFFFFFFFFFFFFFFF";
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
bool Sensor::handleCloud(const char *eventName, const char *data) { // data is format "sID,rate"
  // extract target sensor_id and new updateRate
  String dataString = String(data);
  uint16_t idx = dataString.indexOf(',');
  String targetSID = dataString.substring(0,idx);
  uint32_t newRate = dataString.substring(idx+1).toInt();
  Serial.printlnf("targetSID: %s, newRate: %d", (const char *)targetSID, newRate);

  // Check if sID matches and set new rate
  if(String(_sensor_id) == targetSID) {
    _publishRate = newRate;
  }
  return true;
}
