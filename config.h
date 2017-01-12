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
    - Omni Button and LED configuration
*/

#ifndef config_h
#define config_h

//*****************************************************************************
//*****************************************************************************
//*********************** Hardware Selector ***********************************
//*****************************************************************************
//*****************************************************************************

  //Select a predifined hardware profile or use custom
  //      Cannot be mixed (ie, cannot select PCB_010317 and modify some values in
  //                        custom configuration)
  //#define custom_hardware // Uncomment if using custom hardware
    #ifndef custom_hardware
      #define PCB_010317 // Second prototype, ordered 1/3/17, yellow solder mask
    #endif

//*****************************************************************************
//*****************************************************************************
//*********************** Custom Hardware Mixer *******************************
//*****************************************************************************
//*****************************************************************************
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
      #define POWER_VOLTAGE_LEVEL { 120, 24}

      // Max Current (milli-amps)
      //        [Port0, Port1, Port2, Port3]
      #define MAX_TOTAL_CURRENT 15000
      #define PORT_MAX_CURRENT { 15000, 15000 }

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
    //=========================================================================
    //========================== Current Monitoring ===========================
    //=========================================================================
      #define ENABLE_CURRENT_MONITORING // Comment line if not using current monitoring
        #ifdef ENABLE_CURRENT_MONITORING

        // Current Monitor Type
        //      0: Hall Sensor Raw
        //      1: DRV5053 RAW - Hall Sensor
        //            [Power Port1, Power Port2, ...]
        #define CURRENT_MONITOR_TYPE { 0, 1 }

        //TODO create the "trim" default values
        #endif

    //=========================================================================
    //========================== Omni Button ==================================
    //=========================================================================
      #define ENABLE_OMNI_BUTTON // Comment line if not using omni button
        #ifdef ENABLE_OMNI_BUTTON
          // Omni Button Type
          //    0: Momentary active low
          //    1: Momentary active high
          //    2: Capacitive - Not Implemented
          //    3: LED (button is omni LED that detects when user touches) Not Implemented
          #define OMNI_BUTTON_TYPE 0

          // Internal pullup
          //    0: Use external resistor
          //    1: Use internal pullup resistor - can only be used with active low
          //          ie. OMNI_BUTTON_TYPE == 0
          #define OMNI_BUTTON_PULLUP 0

          // Debounce time
          //  Amount of time to wait for the button to be considered "debounced"
          //    unit: milliseconds
          #define DEBOUCE_TIME 50

          // Long Press time
          //  Amount of time the omni button is pressed to initial a "long press"
          //    unit: milliseconds
          #define LONG_PRESS_TIME 1500

          // Multiclick time
          //  Amount of time alloted for a multipress of the button (double tap)
          //  Too much time results in poor UI
          //    unit: milliseconds
          #define MULTICLICK_TIME 300
        #endif

    //=========================================================================
    //========================== Omni LED ==================================
    //=========================================================================
      #define ENABLE_OMNI_LED // Comment line if not using omni LED
        #ifdef ENABLE_OMNI_LED
          //Omni LED Type
          //    0: Single Color
          //    1: RGB
          #define OMNI_LED_TYPE 0

          // Blink Rate - Half cycle blink Rate - unit: milliseconds
          #define OMNI_LED_BLINK_RATE 250

          // Breathe Rate - Half cycle breathe rate (fade in and out)
          //  unit: milliseconds
          #define OMNI_LED_BREATE_RATE 1000
        #endif
  #endif


//*****************************************************************************
//*****************************************************************************
//*********************** PCB_010317 ******************************************
//*****************************************************************************
//*****************************************************************************
  #ifdef PCB_010317
    #include "pins010317.h"

    #define NUM_POWER_PORTS 2
    #define POWER_CONTROLLER_TYPE { 0, 0 }
    #define POWER_VOLTAGE_TYPE { 0, 0 }
    #define POWER_VOLTAGE_LEVEL { 120, 120}
    #define MAX_TOTAL_CURRENT 15000
    #define PORT_MAX_CURRENT { 15000, 15000 }

    #define ENABLE_WIRELESS_SENSORS
      #ifdef ENABLE_WIRELESS_SENSORS
        #define MAX_WIRELESS_SENSORS 15
      #endif

    #define ENABLE_WIRED_SENSORS
      #ifdef ENABLE_WIRED_SENSORS
        #define NUM_WIRED_PORTS 1
        #define WIRED_PORT_TYPE { 2 }
      #endif

    #define ENABLE_CURRENT_MONITORING
      #ifdef ENABLE_CURRENT_MONITORING
        #define CURRENT_MONITOR_TYPE { 1, 1 }
      #endif

    #define ENABLE_OMNI_BUTTON
      #ifdef ENABLE_OMNI_BUTTON
        #define OMNI_BUTTON_TYPE 0
        #define OMNI_BUTTON_PULLUP 0
        #define DEBOUCE_TIME 50
        #define LONG_PRESS_TIME 1500
        #define MULTICLICK_TIME 300
      #endif

    #define ENABLE_OMNI_LED
      #ifdef ENABLE_OMNI_LED
        #define OMNI_LED_TYPE 0
        #define OMNI_LED_BLINK_RATE 250
        #define OMNI_LED_BREATE_RATE 1000
      #endif
  #endif







#endif
