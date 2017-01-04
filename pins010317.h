/*
pins010317.h

Pin mapping for first model of powertroll pcb, released 1/3/17
*/

#ifndef pins_h
#define pins_h

#define SDA_PIN D0 // Main Function: I2C, Addl: GPIO, PWM
#define SCL_PIN D1 // Main Function: I2C, Addl: GPIO, PWM
#define AUX_I2C_EN_PIN D2 // Main Function: Enable I2C to be used on the wired connector, Addl: GPIO, PWM(A5)
#define NRF_EN_PIN D3 // Main Function: Enable NRF24 Radio, Addl: GPIO, PWM(A4), JTAG_TRST
#define NRF_IRQ_PIN D4 // Main Function: NRF24 Interrupt, Addl: GPIO, JTAG_TDO
#define PIN18 D5 // Unused, Addl: GPIO, JTAG_TDI
#define SSR1_PIN D6 // Main Function: SSR1 Control, Addl: GPIO, JTAG_TCK
#define SSR2_PIN D7 // Main Function: SSR2 Control, Addl: GPIO, JTAM_TMS

#define CRNT1_PIN A0 // Main Function: Measure current on power channel 1, Addl: ADC, GPIO
#define CRNT2_PIN A1 // Main Function: Measure current on power channel 2, Addl: ADC, GPIO
#define NRF_SS_PIN A2 // Main Function: NRF24 SPI Slave Select, Addl: ADC, GPIO
#define SCK_PIN A3 // Main Function: SPI Clock, Addl: ADC, GPIO, DAC
#define MISO_PIN A4 // Main Function: SPI Master IN, Addl: ADC, GPIO, PWM(D3)
#define MOSI_PIN A5 // Main Function: SPI Master OUT, Addl: ADC, GPIO, PWM(D2)
#define SNSR2_PIN A6 // Main Function: Wired Sensor Analog 2, Addl: ADC, DAC, GPIO
#define SNSR1_PIN A7 // Main Function: Wired Sensor Analog 1, Addl: ADC, GPIO, PWM

#define OMNI_LED_PIN RX // Main Function: OMNI LED Control, Addl: UART1 RX, GPIO, PWM
#define OMNI_SW_PIN TX // Main Function: OMNI Button Control, Addl: UART2 TX, GPIO, PWM

#endif
