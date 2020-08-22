#include <avr/io.h>

#define SPI_PINS DDRB
#define SCK 5
#define MISO 4
#define MOSI 3
#define SS 2
#define SPI_PORTS PORTB

void init_spi(void);
uint8_t spi_transfer_data(uint8_t data);