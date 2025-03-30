#include "lcd.h"

static void lcd_enable_pulse(void) {
    LCD_CTRL_PORT |= (1 << LCD_EN);
    _delay_us(1);
    LCD_CTRL_PORT &= ~(1 << LCD_EN);
    _delay_us(100);
}

void lcd_send_command(uint8_t command) {
    // Send upper nibble
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
    LCD_CTRL_PORT &= ~(1 << LCD_RS);  // RS = 0 for command
    lcd_enable_pulse();

    // Send lower nibble
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((command << 4) & 0xF0);
    lcd_enable_pulse();
}

void lcd_write_character(uint8_t character) {
    // Send upper nibble
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (character & 0xF0);
    LCD_CTRL_PORT |= (1 << LCD_RS);  // RS = 1 for data
    lcd_enable_pulse();

    // Send lower nibble
    LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((character << 4) & 0xF0);
    lcd_enable_pulse();
}

void lcd_init(void) {
    // Set data and control pins as output
    LCD_DATA_DDR |= (1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7);
    LCD_CTRL_DDR |= (1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_EN);

    _delay_ms(20);  // Wait for LCD to power up

    // Set LCD to 4-bit mode
    lcd_send_command(0x02);

    // Function Set: 2 line, 5x7 matrix
    lcd_send_command(LCD_CMD_4BIT_2ROW_5X7);
    _delay_ms(5);

    // Display ON, cursor OFF
    lcd_send_command(LCD_CMD_DISPLAY_ON_CURSOR_OFF);
    _delay_ms(5);

    // Clear Display
    lcd_clear();
}

void lcd_clear(void) {
    lcd_send_command(LCD_CMD_CLEAR_DISPLAY);
    _delay_ms(2);
}

void lcd_write_string(const char* str) {
    while (*str) {
        lcd_write_character(*str++);
    }
}

void lcd_setCursor(uint8_t row, uint8_t col) {
    uint8_t address = 0x00;

    if (row == 1) {
        address = 0x40;
    }

    address += col;
    lcd_send_command(0x80 | address);
}
