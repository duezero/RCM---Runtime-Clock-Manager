/* 
 * MIT License

Copyright (c) 2017 duezero

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 
 *
 * v1.1 first release 12/03/2017 
 * 
 
*/

#ifndef RCM_h
#define RCM_h

#include "Arduino.h"


#define presc_1 (0 << CLKPCE) | (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0)
#define presc_2 (0 << CLKPCE) | (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (1 << CLKPS0)
#define presc_4 (0 << CLKPCE) | (0 << CLKPS3) | (0 << CLKPS2) | (1 << CLKPS1) | (0 << CLKPS0)
#define presc_8 (0 << CLKPCE) | (0 << CLKPS3) | (0 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0)
#define presc_16 (0 << CLKPCE) | (0 << CLKPS3) | (1 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0)
#define presc_32 (0 << CLKPCE) | (0 << CLKPS3) | (1 << CLKPS2) | (0 << CLKPS1) | (1 << CLKPS0)
#define presc_64 (0 << CLKPCE) | (0 << CLKPS3) | (1 << CLKPS2) | (1 << CLKPS1) | (0 << CLKPS0)
#define presc_128 (0 << CLKPCE) | (0 << CLKPS3) | (1 << CLKPS2) | (1 << CLKPS1) | (1 << CLKPS0) 
#define presc_256 (0 << CLKPCE) | (1 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0) 
#define clkSet (1 << CLKPCE) | (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0)


#if F_CPU == 20000000L
#define clk_20MHz       1               // not tested
#define clk_10MHz       2               // not tested
#define clk_5MHz        3               // not tested
#define clk_2500kHz     4               // not tested
#define clk_1250kHz     5               // not tested
#define clk_625kHz      6               // not tested
#define clk_312kHz      7  // 312.500   // not tested
#define clk_156kHz      8  // 156.250   // not tested
#define clk_78kHz       9   // 78.125   // not tested


#elif F_CPU == 16000000L
#define clk_16MHz       1               // not tested     
#define clk_8MHz        2               // not tested
#define clk_4MHz        3               // not tested
#define clk_2MHz        4               // not tested
#define clk_1MHz        5               // not tested
#define clk_500kHz      6               // not tested
#define clk_250kHz      7               // not tested
#define clk_125kHz      8               // not tested
#define clk_62kHz       9 //62.500      // not tested


#elif F_CPU == 8000000L
#define clk_8MHz        1
#define clk_4MHz        2
#define clk_2MHz        3
#define clk_1MHz        4
#define clk_500kHz      5
#define clk_250kHz      6               // not recommended
#define clk_125kHz      7               // not recommended
#define clk_62kHz       8 // 62.500     // not recommended
#define clk_31kHz       9 //31.250      // not recommended


#elif F_CPU == 1000000L
#define clk_8MHz        1
#define clk_4MHz        2
#define clk_2MHz        3
#define clk_1MHz        4
#define clk_500kHz      5
#define clk_250kHz      6               // not recommended
#define clk_125kHz      7               // not recommended
#define clk_62kHz       8 // 62.500     // not recommended
#define clk_31kHz       9 //31.250      // not recommended

#endif

//*****************************************************************

extern void RCM_RescueMode();
extern void SetClock(byte clk);

#endif