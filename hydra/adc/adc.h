#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void adc_init(void);
uint16_t adc_read(uint8_t channel);
float LM35_getTemperature();

#endif

/*

#include <avr/io.h>
#include <util/delay.h>
#include "adc/adc.h"
#include "io/io.h"

int main(void)
{
    // Initialize the ADC
    adc_init();

    // Set PB0 as output for LED control
    pinMode('C', 2, OUTPUT);

    // Set PA0 as input for ADC (no need to explicitly set pinMode for analog input, but done for clarity)
    pinMode('A', 1, INPUT);

    uint16_t adc_result;

    while (1)
    {
        // Read the ADC value from channel 1 (PA1)
        adc_result = adc_read(1);

        // Simple control: If the ADC value is greater than 512, turn on the LED
        if (adc_result > 512) {
            digitalWrite('C', 2, HIGH);  // Turn on LED at PB0
        } else {
            digitalWrite('C', 2, LOW);   // Turn off LED at PB0
        }

        _delay_ms(500);  // Delay for debounce
    }
    return 0;
}


*/
