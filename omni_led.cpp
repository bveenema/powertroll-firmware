#include "omni_led.h"

omni_led::omni_led() {
  // Configure the LED pin as an output and turn it off, initialize settings
  pinMode(OMNI_LED_PIN, OUTPUT);
  digitalWrite(OMNI_LED_PIN, OMNI_LED_OFF);
  _mode = 0;
  _maxBrightness = OMNI_LED_BRIGHTNESS;
  _lastUpdateTime = 0;
  #if OMNI_LED_TYPE == 0
    _lastBrightness = 0;
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
      if(_lastBrightness == 0) { // LED is OFF
        driveLED(_maxBrightness); // Turn LED ON
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

void omni_led::set(uint8_t newMode) {
  // if new mode == old mode, or non-valid do nothing
  if(newMode == _mode || mode > NUM_MODES-1) return;

  _mode = newMode;
  // if new mode == 0 (OFF), shut off LED
  if(_mode == 0) {
    driveLED(0);
    return;
  }

  // if new mode == 1 (ON), turn on LED max brightness
  if(_mode == 1) {
    driveLED(_maxBrightness);
    return;
  }

  // if new mode == 2 (MIRROR), set up LED to mirror RGB brightness TODO
  if(_mode == 2) {
    return;
  }

  // if new mode == 3 or 4 (BLINK or BREATHE), turn off LED, set _lastUpdateTime
  // to current time
  if(_mode == 3 || _mode == 4) {
    driveLED(0);
    _lastUpdateTime = millis();
    return;
  }

  return;
}

#if OMNI_LED_TYPE == 1
  void omni_led::set(uint8_t newMode, uint8_t R, uint8_t G, uint8_t B) {
    // call single argument version of set
    set(newMode);

    // if LED is mirroring particle led, do no set new color.
    if(_mode == 2) return;

    // set the new RGB color,
    if(_mode < NUM_MODES) {
      driveLED(_lastBrightness, R, G, B);
    }

    return;
  }
#endif // OMNI_LED_TYPE == 1


uint8_t omni_led::calculateBreath(){}

void omni_led::driveLED(uint8_t brightness) {
  // set _lastBrightness to brightness, update PWM output
  _lastBrightness = brightness;
  analogWrite(OMNI_LED_PIN, _lastBrightness);
  return;
}

#if OMNI_LED_TYPE == 1
  void omni_led::driveLED(uint8_t brightness, Rduty, uint8_t Gduty, uint8_t Bduty) {
    // set _last[values] to newValues
    _lastBrightness = brightness;
    _last_R_duty = Rduty;
    _last_G_duty = Gduty;
    _last_B_duty = Bduty;

    // calculate PWM outputs. ex. R_PWM = Rduty * (brightness / 255)
    uint16_t R_PWM = _last_R_duty * _lastBrightness / 255;
    uint16_t G_PWM = _last_G_duty * _lastBrightness / 255;
    uint16_t B_PWM = _last_B_duty * _lastBrightness / 255;

    // update PWM output
    analogWrite(OMNI_LED_R_PIN, R_PWM);
    analogWrite(OMNI_LED_G_PIN, G_PWM);
    analogWrite(OMNI_LED_B_PIN, B_PWM);
  }
#endif // OMNI_LED_TYPE == 1

/*
#if OMNI_LED_TYPE == 0
  uint8_t _lastBrightness;
#endif //OMNI_LED_TYPE == 0

#if OMNI_LED_TYPE == 1
  uint8_t _lastBrightness, _last_R_duty, _last_G_duty, _last_B_duty;
#endif //OMNI_LED_TYPE == 1

uint8_t _mode, _brightness;
uint32_t _lastUpdateTime;
*/