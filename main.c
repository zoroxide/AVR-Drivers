#include "interrubt/interrupt.h"
#include "io/io.h"

ISR(INT0_vect)
{
    PORTC=~PORTC;
    _delay_ms(20);
}

int main()
{
    writePort('C');

    pinMode('D', 2, INPUT);

    init_interrupt(0);
    MCUCR = 1<<ISC01 | 1 <<ISC00;

    sei();

    while(1);



    return 0;
}

