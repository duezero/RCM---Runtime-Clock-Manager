
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
*/

#include <RCM.h>
/*
 * v1.1 first release 12/03/2017
 * 
 *
 * 
 *  ********** 20MHz CLOCK *********    *** prescaler value *** 
 *  clk_20MHz                                   1
 *  clk_10MHz                                   2  
 *  clk_5MHz                                    4  
 *  clk_2500kHz                                 8  
 *  clk_1250kHz                                 16  
 *  clk_625kHz                                  32  
 *  clk_312kHz  // 312.500                      64  
 *  clk_156kHz  // 156.250                      128
 *  clk_78kHz   // 78.125                       256
 * 
 *  ********** 16MHz CLOCK *********    *** prescaler value *** 
 *  clk_16MHz                                   1
 *  clk_8MHz                                    2  
 *  clk_4MHz                                    4  
 *  clk_2MHz                                    8  
 *  clk_1MHz                                    16  
 *  clk_500kHz                                  32  
 *  clk_250kHz                                  64  
 *  clk_125kHz                                  128  
 *  clk_62kHz   // 62.500                       256
 * 
 * ********* 8MHz CLOCK *********       *** prescaler value *** 
 *  clk_8MHz                                    1  
 *  clk_4MHz                                    2  
 *  clk_2MHz                                    4  
 *  clk_1MHz                                    8  
 *  clk_500kHz                                  16  
 *  clk_250kHz                                  32  
 *  clk_125kHz                                  64  
 *  clk_62kHz   // 62.500                       128
 *  clk_31kHz   // 31.250                       256
 * 
 *
 */

#define pin  8

void setup() {
    pinMode(pin,OUTPUT);
  //RCM_RescueMode();           // uncomment this line to enable rescue mode
    SetClock(clk_1MHz);         // this function can be called either in setup or loop
}

void loop() {
digitalWrite(pin,HIGH);
delay(1000);
digitalWrite(pin,LOW);
delay(1000);

}
