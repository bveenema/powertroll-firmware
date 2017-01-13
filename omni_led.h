/*
omni_led.h

Omni LED Driver - The omni led is the "quick glance" UI element for the troll.
  It gives users a quick insight to issues or feedback to interaction with the button.
  Not meant to replace a smartphone or computer for all/most interactions.

  Can be configured as a single color or an RGB lED (TODO) in config.h

  Requires frequent updates (calling omni_led.update), min rate TBD.

  Has the following modes (update NUM_MODES when adding new modes):
    0: Constant OFF
    1: Constant ON
    2: Mirror photon LED (in single color mode only pattern is mirrored)
    3: Blink (Rate determined in config.h)
    4: Breathe (Fade IN and OUT, rate determined in config.h)

  Modes are set by calling omni_led.set(int mode, [int R, int G, int B])

  Brightness is set by calling omni_led.brightness( int brightness (0-255) )
  Sets the brightness of the LED when on and the max value it will breathe to.

  _lastUpdateTime is used differently for blink and breathe.  With breathe, it is
  updated every time update is called, with blink, it is only updated when the led
  transitions from ON to OFF or OFF to ON.
*/

#ifndef omni_led_h
#define omni_led_h
  #ifdef ENABLE_OMNI_LED
  #include "application.h"
  #define NUM_MODES = 5

    class omni_led {
    public:
      omni_led();
      void update();
      void brightness(uint8_t newBrightness);
      void set(uint8_t newMode);
      #if OMNI_LED_TYPE == 1
        void set(uint8_t newMode, uint8_t R, uint8_t G, uint8_t B);
      #endif // OMNI_LED_TYPE == 1

    private:
      uint8_t calculateBreath(uint32_t currentTime);
      void driveLED(uint8_t brightness);
      #if OMNI_LED_TYPE == 1
        void driveLED (uint8_t brightness, Rduty, uint8_t Gduty, uint8_t Bduty);
      #endif // OMNI_LED_TYPE == 1

      #if OMNI_LED_TYPE == 0
        uint8_t _lastBrightness;
      #endif //OMNI_LED_TYPE == 0
      #if OMNI_LED_TYPE == 1
        uint8_t _lastBrightness, _last_R_duty, _last_G_duty, _last_B_duty;
      #endif //OMNI_LED_TYPE == 1
      uint8_t _mode, _maxBrightness;
      uint32_t _lastUpdateTime;
    }

    omni_led omni_led;

  #endif //ENABLE_OMNI_LED
#endif //omni_led_h
