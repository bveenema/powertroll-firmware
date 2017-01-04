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
	Sensor(int16_t memAddress);
	bool checkForData();
	int32_t getData();
	bool checkHealth();
	bool getHealth();
	bool shouldPublish();
	bool recieveSettings(const char *id, uint32_t publishRate, uint32_t updateRate);

// These will be protected/private
  bool publishData(int32_t data);
	bool detectNewSensor(void);
	bool saveMem(void);
	bool loadMem(void);
  bool registerCloud(String sensor_id, String type, bool isWireless);

private:

  char [18];
  uint32_t _publishRate;
	bool _lastPublish;
	uint32_t _updateRate;
	int32_t _currentData;
	bool _hasNewData;
	uint32_t _lastDataTime;
	bool _isAlive;

};

#endif
