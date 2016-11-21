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
  bool publishData(int32_t data);
  bool registerCloud(uint32_t sensor_id, String type, bool isWireless);

private:
  bool handleCloud(const char *eventName, const char *data);

  uint32_t _sensor_id;
  uint32_t _publishRate;

};

#endif
