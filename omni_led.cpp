#include "omni_led.h"

omni_led::omni_led() {
  // Configure the LED pin as an output and turn it off, initialize settings
  pinMode(OMNI_LED_PIN, OUTPUT);
  digitalWrite(OMNI_LED_PIN, OMNI_LED_OFF);
  _mode = 0;
  _brightness = OMNI_LED_BRIGHTNESS;
  _lastUpdateTime = 0;
  #if OMNI_LED_TYPE == 0
    _lastDuty = 0;
  #endif //OMNI_LED_TYPE == 0

  #if OMNI_LED_TYPE == 1
    _last_R_duty = 0; _last_G_duty = 0; _last_B_duty = 0;
  #endif //OMNI_LED_TYPE == 1
}

void omni_led::update(){
  // perform any necessary calculations and call driveLED if new duty value
  if(_mode < 2) { //mode is either constant ON or OFF
    return;
  } else if(_mode == 2) { // mirror photon led
    return;
  } else if(_mode == 3) { // blink

    uint32_t currentTime = millis();
    if(currentTime - _lastUpdateTime > OMNI_LED_BLINK_RATE) {
      if(_lastDuty == 0) { // LED is OFF
        driveLED(_brightness); // Turn LED ON
      } else {
        driveLED(0); // turn LED OFF
      }
      _lastUpdateTime = currentTime;
    }

  } else if(_mode == 4) { // breathe

    uint32_t currentTime = millis();
    uint8_t newDuty = calculateBreath(currentTime);
    driveLED(_newDuty);
    _lastUpdateTime = currentTime;

  }

  return;
}

void omni_led::set(uint8_t newMode)

#if OMNI_LED_TYPE == 1
  void omni_led::set(uint8_t newMode, uint8_t R, uint8_t G, uint8_t B)

#endif // OMNI_LED_TYPE == 1


uint8_t omni_led::calculateBreath()

void omni_led::driveLED(uint8_t duty)

#if OMNI_LED_TYPE == 1
  void omni_led::driveLED (uint8_t Rduty, uint8_t Gduty, uint8_t Bduty)

#endif // OMNI_LED_TYPE == 1

/*
#if OMNI_LED_TYPE == 0
  uint8_t _lastDuty;
#endif //OMNI_LED_TYPE == 0

#if OMNI_LED_TYPE == 1
  uint8_t _last_R_duty, _last_G_duty, _last_B_duty;
#endif //OMNI_LED_TYPE == 1

uint8_t _mode, _brightness;
uint32_t _lastUpdateTime;
*/
