#include "interrupt.h"

void init_interrupt(int num){
    switch(num){
    case 0:
        GICR=1<<INT0;
        break;
    case 1:
        GICR=1<<INT1;
        break;
    case 2:
        GICR=1<<INT2;
        break;
    }
}
