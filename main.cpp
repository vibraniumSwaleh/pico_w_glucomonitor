#include <iostream>
#include "pico/stdlib.h"
#include "hardware/spi.h"

//SPI configuration ( #NOTE# -> These are GPIO numbers not PIN numbers)
// #define PIN_SPI_MISO 
#define PIN_SPI_CS 9
#define PIN_SPI_SCK 10
#define PIN_SPI_MOSI 11
#define SPI_PORT spi1

/**
 * SPI write functions
**/
void DEV_SPI_WriteByte(uint8_t Value)
{
    spi_write_blocking(SPI_PORT, &Value, 1);
}

void DEV_SPI_Write_nByte(uint8_t pData[], uint32_t Len)
{
    spi_write_blocking(SPI_PORT, pData, Len);
}


int main(){
    //Initialize stdio/uart for output display  
    stdio_init_all();

    cout << " We are setting up SPI ...\n";

    //Initialize SPI protocal


}