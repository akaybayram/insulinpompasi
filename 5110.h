#include <avr/io.h>
#include "SPI.h"

#define LCD_PORT PORTC
#define LCD_DDR DDRC
#define LCD_DC PC0
#define LCD_RST PC1
#define LCD_CE PC2

#define LCD_DATA 1
#define LCD_COMMAND 0

#define BLACK 1
#define WHITE 0

void lcd_send_byte(uint8_t sendMode ,uint8_t byte);
void set_contrast(int8_t contrast);
void init_lcd(int8_t contrast);
