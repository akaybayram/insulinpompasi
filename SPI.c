#if !defined(__AVR_ATmega328P__)
#define __AVR_ATmega328P__
#endif // __AVR_ATmega328P__


#include "SPI.h"

void init_spi(void)
{
    SPI_PINS = (1 << MOSI) | (1 << SCK) | (1 << SS) ; //MOSI,SCK,SS pinleri çıkış olarak ayarlandı.
    SPCR = ( 1 << SPE ) | ( 1 << MSTR ) | ( 1 << SPR0 ) ; // SPI aktif , master cihaz , 1MHz iletim hızı
}

uint8_t spi_transfer_data(uint8_t data)
{
    SPDR = data; // Veri yazmaça yazılır
    while (!( SPSR & ( 1 << SPIF ))); // iletimin bitmesi beklenir.

    return SPDR;
}