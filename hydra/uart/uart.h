#ifndef UART_H
#define UART_H

#include <avr/io.h>

#define BAUD 9600
#define MY_UBRR F_CPU/16/BAUD-1

void uart_init(unsigned int ubrr);
void uart_transmit(unsigned char data);
unsigned char uart_receive(void);
void uart_send_string(const char *str);

#endif

/*
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void)
{
    // Initialize UART with baud rate 9600
    uart_init(MY_UBRR);

    while (1)
    {
        // Send a string via UART
        uart_send_string("Hello, UART!\r\n");

        _delay_ms(1000);  // Delay for 1 second
    }

    return 0;
}

*/
