#if !defined(__AVR_ATmega328P__)
#define __AVR_ATmega328P__
#endif // __AVR_ATmega328P__

#include "5110.h"

void lcd_send_byte(uint8_t sendMode ,uint8_t byte)
{
    if(sendMode)
    {
        LCD_PORT |= ( 1 << LCD_DC );
    }
    else
    {
        LCD_PORT &= ~( 1 << LCD_DC );
    }

    LCD_PORT &= ~( 1 << LCD_CE );
    spi_transfer_data( byte );
    LCD_PORT |= ( 1 << LCD_CE );
}

void set_contrast(int8_t contrast)
{
    lcd_send_byte(LCD_COMMAND, 0x21); // extended instruction
    lcd_send_byte(LCD_COMMAND, 0x80 | contrast); // contrast ayarı 0-127 arası
    lcd_send_byte(LCD_COMMAND, 0x20); // chip is active, horizontal adressing,basic instruction set
}

void init_lcd(int8_t contrast)
{
    //Çıkışlar ayarlanır.
    LCD_DDR |= ( 1 << LCD_DC ) | ( 1 << LCD_RST ) | ( 1 << LCD_CE );

    // Reset işlemi
    LCD_PORT &= ~( 1 << LCD_RST );
    LCD_PORT |= ( 1 << LCD_RST );

    // Ayar işlemleri
    lcd_send_byte(LCD_COMMAND, 0x21); //extended insruction modu
    lcd_send_byte(LCD_COMMAND, 0xB0); // set Vop
    lcd_send_byte(LCD_COMMAND, 0x04); // set temp coefficent 0
    lcd_send_byte(LCD_COMMAND, 0x14); // chip is power-down mode
    lcd_send_byte(LCD_COMMAND, 0x20); // chip is active, horizontal adressing,basic instruction set
    lcd_send_byte(LCD_COMMAND, 0x0C); // Display option = normal mode

    set_contrast(contrast);
}