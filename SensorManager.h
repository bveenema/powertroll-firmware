/*
** SensorManager.h
** Object for managing the sensors
** Output:
** Input:
** Platform: Particle Photon
** Author: Benjamin Veenema - Veenema Design Works
** Date Created: 11/25/16
*/

#ifndef SensorManager_h
#define SensorManager_h

#include "application.h"
#include <vector>

extern std::vector<Sensor> sensors;

class SensorManager{
public:
	SensorManager(int16_t memAddress);
  bool initializeSensors(void);



private:

  uint8_t checkId(char *id);
  uint

  std::vector<uint16_t> memoryPositions;
  uint8_t sensorMemSize;
  uint16_t minPublish;
  uint32_t lastPublish;
  std::vector<char [18]> ignoreList;
  // Publish Buffer


};

#endif
