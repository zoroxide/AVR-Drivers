#include "adc.h"

/*
 * Function: adc_init
 * Purpose: Initializes the ADC by configuring the ADC registers
 */
void adc_init(void) {
    // Set the reference voltage to AVCC (5V) and adjust result to the right
    ADMUX = (1 << REFS0);  // REFS0 = 1 selects AVCC as the reference, ADLAR = 0 (right adjustment)

    // Enable ADC, set prescaler to 64 (for 16MHz clock)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);  // ADEN = 1 enables ADC, ADPS2:ADPS0 = 011 for prescaler of 64
}

/*
 * Function: adc_read
 * Parameters:
 *    - channel: The ADC channel to read from (0-7)
 * Returns: The ADC conversion result (10-bit value)
 */
uint16_t adc_read(uint8_t channel) {
    // Select the ADC channel (0-7) and mask out any high bits (ADMUX[3:0] for channel select)
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);  // Preserve REFS bits and adjust channel bits

    // Start the ADC conversion
    ADCSRA |= (1 << ADSC);  // ADSC = 1 starts the conversion

    // Wait for the conversion to complete (ADIF flag is set when done)
    while (ADCSRA & (1 << ADSC));  // Wait for ADSC bit to clear (conversion complete)

    // Return the ADC value (10-bit result from ADCL and ADCH)
    return ADC;
}

float LM35_getTemperature() {
    uint16_t adcValue = adc_read(0);  // Read from ADC channel 0 (assuming LM35 is connected here)
    float voltage = (adcValue / 1024.0) * 5000;  // Convert ADC value to voltage (assuming 5V Vref)
    float temperature = voltage / 10.0;  // LM35 gives 10mV per degree Celsius
    return temperature;
}