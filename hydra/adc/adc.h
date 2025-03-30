#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void adc_init(void);
uint16_t adc_read(uint8_t channel);
float LM35_getTemperature();

#endif

/*

#include "hydra/adc/adc.h"
#include "hydra/io/io.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  adc_init();

  pinMode('C', 2, OUTPUT);
  pinMode('C', 7, OUTPUT);

  // Set PA0 as input for ADC (no need to explicitly set pinMode for analog
  // input, but done for clarity)
  pinMode('A', 1, INPUT);

  uint16_t adc_result = 0;

  while (1) {
    // Read the ADC value from channel 1 (PA1)
    adc_result = adc_read(1);

    if (adc_result > 512) {
      digitalWrite('C', 2, HIGH);
    } else if (adc_result < 512) {
      digitalWrite('C', 7, HIGH);
    } else {
      digitalWrite('C', 2, LOW);
      digitalWrite('C', 7, LOW);
    }

    _delay_ms(500); // Delay for debounce
  }
  return 0;
}


*/
