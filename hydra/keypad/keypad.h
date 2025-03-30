#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../lib/util_bits.h"
#include "../lib/Std_Types.h"

#include <avr/io.h>

#define Keypad_Port_Dir DDRA
#define Keypad_Port_Out PORTA
#define Keypad_Port_In PINA
#define N_Col 3
#define N_Row 4

uint8 Keypad_GetPressedKey();
uint8 Keypad_4x3(uint8 Num);


#endif /* KEYPAD_H_ */
