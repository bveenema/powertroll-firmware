/*
** Sensor.h
** Base sensor class.  Handles cloud functions.
** Output:
** Input:
** Platform: Particle Photon
** Author: Benjamin Veenema - Veenema Design Works
** Date Created: 11/20/16
*/

#ifndef Sensor_h
#define Sensor_h

#include "application.h"

class Sensor{
public:
	Sensor(void);
	bool checkForData();
	int32_t getData();
	bool checkHealth();

// These will be protected/private
  bool publishData(int32_t data);
	bool recieveSettings(void);
	bool detectNewSensor(void);
	bool saveMem(void);
	bool loadMem(void);
  bool registerCloud(String sensor_id, String type, bool isWireless);

private:

  const char *_sensor_id;
  uint32_t _publishRate;
	uint32_t _updateRate;
	int32_t _currentData;
	bool hasNewData;
	uint32_t _lastDataTime;
	bool isAlive;

};

#endif
