/*
Config.h

  Controller settings, such as:
    - Number of power outlets
    - AC/DC power
    - Power Voltage (24VDC, 120VAC, 240VAC etc.)
    - Power control method (PWM, AC Phase etc.)
    - Number of wired sensor ports
    - Available protocols for wired sensors
    - Max Wireless sensors
    - Enable/Disable wireless or wired sensors
    - Wireless radio configuration
    - Enable/Disable/Configure current monitoring
*/

#ifndef config_h
#define config_h

/* Select a predifined hardware profile or use custom
      Cannot be mixed (ie, cannot select PCB_010317 and modify some values in
                        custom configuration)
*/
//#define custom_hardware
  #ifndef custom_hardware
    #define PCB_010317
  #endif

#ifdef custom_hardware
/* Custom Hardware Mixer








#endif
