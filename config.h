/*
Config.h

  Controller settings, such as:
    - Number of power outlets
    - AC/DC power
    - Power Voltage (24VDC, 120VAC, 240VAC etc.)
    - Power Max Current
    - Power control method (PWM, AC Phase etc.)
    - Number of wired sensor ports
    - Available protocols for wired sensors
    - Max Wireless sensors
    - Enable/Disable wireless or wired sensors
    - Enable/Disable/Configure current monitoring
*/

#ifndef config_h
#define config_h

  /* Select a predifined hardware profile or use custom
        Cannot be mixed (ie, cannot select PCB_010317 and modify some values in
                          custom configuration)
  */
  //#define custom_hardware // Uncomment if using custom hardware
    #ifndef custom_hardware
      #define PCB_010317 // Second prototype, ordered 1/3/17, yellow solder mask
    #endif

  /* Custom Hardware Mixer
  */
  #ifdef custom_hardware
    // Pin Map file -> see pins010317.h for example file
    //                 Naming conventions must be followed
    //                 Change "pins.h"
    #include "pins.h"

    //=========================================================================
    //========================== Power Port Settings ==========================
    //=========================================================================

      // Number of Power Ports, supports up to 4
      #define NUM_POWER_PORTS 2

      // Power Port Type:
      //    0: SSR
      //    1: TRIAC
      //    2: Mechanical Relay
      //        [Port0, Port1, Port2, Port3]
      #define POWER_CONTROLLER_TYPE { 0, 1 }

      // Power Voltage Config
      //    0: AC
      //    1: DC
      //        [Port0, Port1, Port2, Port3]
      #define POWER_VOLTAGE_TYPE { 0, 1 }

      // Max Current (milli-amps)
      //        [Port0, Port1, Port2, Port3]
      #define MAX_TOTAL_CURRENT 15000
      #define POWER_MAX_CURRENT { 15000, 15000 }

    //=========================================================================
    //========================== Wireless Sensors =============================
    //=========================================================================
      #define ENABLE_WIRELESS_SENSORS // Comment line if not using wireless sensors
        #ifdef ENABLE_WIRELESS_SENSORS

        // Max Number of Wireless sensors
        // Wireless sensors use a large amount limited heap memory
        #define MAX_WIRELESS_SENSORS 15

        #endif

    //=========================================================================
    //========================== Wired Sensors ================================
    //=========================================================================
      #define ENABLE_WIRED_SENSORS  // Comment line if not using wired sensors
        #ifdef ENABLE_WIRED_SENSORS

        // Number of Wired Sensor ports
        // Wired sensors must follow the "Wired Sensor Protocol" (TBD) which
        // specifies how the wired sensor interacts with the hardware.
        // Main points:
        //    - 4 Pins:
        //        1: +3.3V
        //        2: Analog1/SDA
        //        3: Analog2/SCL
        //        4: GND
        //    - Analog sensors must return a voltage between 0 - 3.3
        //    - I2C must be of type (TBD)
        #define NUM_WIRED_PORTS 2

        // Wired Sensor available types
        // Which protocols are available on each wired port
        //    0: Analog Only
        //    1: I2C Only
        //    2: Analog and I2C
        //              [Port0, Port1, Port2, ...]
        #define WIRED_PORT_TYPE { 2, 0 }

        #endif

  #endif

  #ifdef PCB_010317
    #include "pins010317.h"


  #endif







#endif
