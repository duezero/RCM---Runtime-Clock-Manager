# RCM---Runtime-Clock-Manager
Arduino library for 8 bit AVR MCUs


 This library allows to change clock frequency at runtime, helping saving energy.
 

 /********** Current consumption **********/
 
 ATmega328p 16MHz 5V on a breadboard:

 *  clk_16MHz   ~16.50 mA
 *  clk_8MHz    ~12.20 mA
 *  clk_4MHz    ~8.92 mA
 *  clk_2MHz    ~8.40 mA
 *  clk_1MHz    ~7.59 mA
 *  clk_500kHz  ~7.25 mA
 *  clk_250kHz  ~7.00 mA		// not recommended
 *  clk_125kHz  ~5.90 mA		// not recommended
 *  clk_62kHz   ~6.65 mA  // 62.500	// not recommended
 
 ATmega328p 8MHz(int. osc.) 5V on a breadboard:

 *  clk_8MHz    ~12.15 mA
 *  clk_4MHz    ~10.25 mA
 *  clk_2MHz    ~8.80 mA
 *  clk_1MHz    ~8.10 mA
 *  clk_500kHz  ~7.70 mA
 *  clk_250kHz  ~7.50 mA                // not recommended
 *  clk_125kHz  ~7.40 mA                // not recommended
 *  clk_62kHz   ~7.30 mA  // 62.500     // not recommended
 *  clk_31kHz   ~7.27 mA  // 31.250     // not recommended

 ATmega328p 8MHz(int. osc.) 3.3V on a breadboard:

 *  clk_8MHz    ~3.87 mA
 *  clk_4MHz    ~2.65 mA
 *  clk_2MHz    ~1.90 mA
 *  clk_1MHz    ~1.38 mA
 *  clk_500kHz  ~1.13 mA
 *  clk_250kHz  ~0.98 mA                // not recommended
 *  clk_125kHz  ~0.82 mA                // not recommended
 *  clk_62kHz   ~0.75 mA  // 62.500     // not recommended
 *  clk_31kHz   ~0.75 mA  // 31.250     // not recommended


 
 ATtiny85 8MHz(int. osc.) 5V on a breadboard:

 *  clk_8MHz    ~8.30 mA
 *  clk_4MHz    ~5.21 mA
 *  clk_2MHz    ~3.08 mA
 *  clk_1MHz    ~2.25 mA
 *  clk_500kHz  ~1.66 mA
 *  clk_250kHz  ~1.37 mA                // not recommended
 *  clk_125kHz  ~1.40 mA                // not recommended
 *  clk_62kHz   ~1.52 mA  // 62.500     // not recommended
 *  clk_31kHz   ~1.64 mA  // 31.250     // not recommended

 ATtiny85 8MHz(int. osc.) 3.3V on a breadboard:

 *  clk_8MHz    ~4.50 mA
 *  clk_4MHz    ~2.90 mA
 *  clk_2MHz    ~1.80 mA
 *  clk_1MHz    ~1.20 mA
 *  clk_500kHz  ~0.90 mA
 *  clk_250kHz  ~0.80 mA                // not recommended
 *  clk_125kHz  ~0.73 mA                // not recommended
 *  clk_62kHz   ~0.68 mA  // 62.500     // not recommended
 *  clk_31kHz   ~0.65 mA  // 31.250     // not recommended
 
 
 
Time-dependant functions like delay(), millis() or Serial() will not work properly when the clock is reduced. This because that functions are set on compile-time, based on f_cpu value defined in boards file. RCM_delay() and RCM_millis() can be used instead of standard delay and millis.

It's not recommended push the clock below 500kHz, for two reasons: 

 * 1 power saving is risible
 * 2 you cannot reprogram the MCU due to low clock.

If you want to experiment with low clocks, uncomment (see example) _RCM_RescueMode();_. This function give you 5 seconds of full clock. The procedure is the sequent:

 * 1 switch off your MCU
 * 2 turn on again the MCU
 * 3 upload new sketch before 5 seconds expires

If you set clock below 500kHz without _RCM_RescueMode()_ active there is still the possibility to program again your MCU. WARNING -- Tested only with Arduino as ISP --

 * 1 Upload on your Arduino the sketch _Arduino ISP low speed_
 * 2 Burn the bootloader
 * 3 Upload on your Arduino the original sketch _Arduino ISP_
 * 4 Upload new sketch on your MCU
