/*
* File: lcd.h
* Author: Loay Mohamed - 11/9/2020
*/

#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>

// Define the LCD control pins and the port
#define LCD_RS PB1
#define LCD_RW PB2
#define LCD_EN PB3
#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_DDR DDRB

// Define the LCD data pins and the port
#define LCD_D4 PA4
#define LCD_D5 PA5
#define LCD_D6 PA6
#define LCD_D7 PA7
#define LCD_DATA_PORT PORTA
#define LCD_DATA_DDR DDRA

// LCD commands
#define LCD_CMD_CLEAR_DISPLAY 0x01
#define LCD_CMD_4BIT_2ROW_5X7 0x28
#define LCD_CMD_DISPLAY_ON_CURSOR_OFF 0x0C

void lcd_init(void);
void lcd_send_command(uint8_t command);
void lcd_write_character(uint8_t character);
void lcd_write_string(const char* str);
void lcd_clear(void);
void lcd_setCursor(uint8_t row, uint8_t col);

#endif
