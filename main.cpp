#include <iostream>
#include "pico/stdlib.h"
#include "hardware/spi.h"

/**
 * SPI configuration ( #NOTE# -> These are GPIO numbers not PIN numbers)
**/
// #define PIN_SPI_MISO
int PIN_SPI_CS 
int PIN_SPI_SCK 
int PIN_SPI_MOSI 
#define SPI_PORT spi1

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/**
 * SPI write functions
**/
void SPI_WriteByte(uint8_t Value)
{
    spi_write_blocking(SPI_PORT, &Value, 1);
}

void SPI_Write_nByte(uint8_t pData[], uint32_t len)
{
    spi_write_blocking(SPI_PORT, pData, len);
}

/**
 * GPIO read and write functions
**/
void Pin_Write(UWORD Pin, UBYTE Value)
{
    gpio_put(Pin, Value);
}

UBYTE Pin_Read(UWORD Pin)
{
    return gpio_get(Pin);
}

/**
 * Pin Mode Config
**/
void Pin_Mode_Config(UWORD Pin, UWORD Mode)
{
    if(Mode == 0 || Mode == GPIO_IN) {
        Pin_IN_Config(Pin);
    } else {
        Pin_OUT_Config(Pin);
    }
}

/**
 * Pin Input Config
**/
void Pin_IN_Config(UWORD Pin)
{
    gpio_init(Pin);
	gpio_pull_up(Pin);
    gpio_set_dir(Pin, GPIO_IN);
}

/**
 * Pin Output Config
**/
void Pin_OUT_Config(UWORD Pin)
{
    gpio_init(Pin);
	gpio_pull_down(Pin);
    gpio_set_dir(Pin, GPIO_OUT);
}

/**
 * delay x ms
**/
void Delay_ms(UDOUBLE xms)
{
    sleep_ms(xms);
}

void Delay_us(UDOUBLE xus)
{
    sleep_us(xus);
}

void Dev_Module_Init(){
    stdio_init_all(); //Initialize stdio/uart for output display

    PIN_SPI_CS 9
    PIN_SPI_SCK 10
    PIN_SPI_MOSI 11
    
    // SPI Config
    spi_init(SPI_PORT, 10000 * 1000);
    gpio_set_function(PIN_SPI_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SPI_MOSI , GPIO_FUNC_SPI);

    Pin_Mode_Config(PIN_SPI_CS, 1);
    Pin_Write(PIN_SPI_CS, 1);

    cout << "DEV_Module_Init OK \r\n";
    
}

int main(){
      
    Dev_Module_Init();
    
    cout << " We are setting up SPI ...\n";
    
    return 0;
}