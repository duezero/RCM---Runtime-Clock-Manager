# RCM---Runtime-Clock-Manager
Arduino library for 8 bit AVR MCUs

 This library allows to change clock frequency at runtime, helping saving energy.
 

 /********** Current consumption **********/
 
 ATmega328 16MHz 5V on a breadboard:

 *  clk_16MHz   xxx mA                  // not tested
 *  clk_8MHz    xxx mA                  // not tested
 *  clk_4MHz    xxx mA                  // not tested
 *  clk_2MHz    xxx mA                  // not tested
 *  clk_1MHz    xxx mA                  // not tested
 *  clk_500kHz  xxx mA                  // not tested
 *  clk_250kHz  xxx mA                  // not tested
 *  clk_125kHz  xxx mA                  // not tested
 *  clk_62kHz   xxx mA  // 62.500       // not tested
 
 ATmega328 8MHz 5V on a breadboard:

 *  clk_8MHz    ~12.15 mA
 *  clk_4MHz    ~10.25 mA  
 *  clk_2MHz    ~8.80 mA  
 *  clk_1MHz    ~8.10 mA  
 *  clk_500kHz  ~7.70 mA  
 *  clk_250kHz  ~7.50 mA                // not recommended
 *  clk_125kHz  ~7.40 mA                // not recommended
 *  clk_62kHz   ~7.30 mA  // 62.500     // not recommended
 *  clk_31kHz   ~7.27 mA  // 31.250     // not recommended
 
 ATtiny85 8MHz 5V on a breadboard:

 *  clk_8MHz    ~8.30 mA
 *  clk_4MHz    ~5.21 mA  
 *  clk_2MHz    ~3.08 mA  
 *  clk_1MHz    ~2.25 mA  
 *  clk_500kHz  ~1.66 mA  
 *  clk_250kHz  ~1.37 mA                // not recommended
 *  clk_125kHz  ~1.40 mA                // not recommended
 *  clk_62kHz   ~1.52 mA  // 62.500     // not recommended
 *  clk_31kHz   ~1.64 mA  // 31.250     // not recommended
 
 
 
Time-dependant functions like delay(), millis() or Serial() will not work properly when the clock is reduced.
