/*
   MIT License

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

   v1.2 added delay and millis 15/03/2018
   v1.1 first release 12/03/2017


*/

#include "Arduino.h"
#include "RCM.h"

byte clockMEM = 0; // last memorized clock
uint16_t prsclr = 1; // prescaler value

void RCM_RescueMode() {
  cli();
  CLKPR = (clkSet);
  CLKPR = (presc_1); // to prevent micro brick due to low clock
  sei();

  if (F_CPU == 1000000L) { // if program is compiled for 1Mhz clock(8MHz clock source, CKDIV8 set), setting the prescaler to 1 means that timers will run 8 times faster
    delay(40000);
  }
  else {
    delay(5000);    // program commpiled for max clock (prescaler == 1)
  }
}
void SetClock(byte clk) {
  if (clk != clockMEM) { // if selected clock is different from last clock memorized
    switch (clk) { // choose clock
      case (1):
        cli();  // disable global interrupt
        CLKPR = (clkSet);
        CLKPR = (presc_1);
        prsclr = 1;
        sei();  // enable global interrupt
        break;
      case (2):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_2);
        prsclr = 2;
        sei();
        break;
      case (3):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_4);
        prsclr = 4;
        sei();
        break;
      case (4):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_8);
        prsclr = 8;
        sei();
        break;
      case (5):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_16);
        prsclr = 16;
        sei();
        break;
      case (6):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_32);
        prsclr = 32;
        sei();
        break;
      case (7):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_64);
        prsclr = 64;
        sei();
        break;
      case (8):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_128);
        prsclr = 128;
        sei();
        break;
      case (9):
        cli();
        CLKPR = (clkSet);
        CLKPR = (presc_256);
        prsclr = 256;
        sei();
        break;
    }
    clockMEM = clk; // update clockMEM value
  }
}
void RCM_delay(unsigned long millisec) {
  delay(millisec / prsclr);
}

unsigned long int RCM_millis() {
  unsigned long int RCMmillis;
  RCMmillis = millis() * prsclr;
  return RCMmillis;
}

