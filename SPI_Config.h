#ifndef _SPI_CONFIG_
#define _SPI_CONFIG_

#include "pico/stdlib.h"
#include "hardware/spi.h" 

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/**
 * GPIOI config
**/
extern int PIN_OLED_RST;
extern int PIN_OLED_DC;
extern int PIN_SPI_CS;
extern int PIN_SPI_SCK;
extern int PIN_SPI_MOSI;

/**
 * SPI write functions
**/
void SPI_WriteByte(uint8_t Value);
void SPI_Write_nByte(uint8_t pData[], uint32_t len);

/**
 * GPIO read and write functions
**/
void Pin_Write(UWORD Pin, UBYTE Value);
UBYTE Pin_Read(UWORD Pin);

/**
 * Pin Mode Config
**/
void Pin_Mode_Config(UWORD Pin, UWORD Mode);

/**
 * Pin Input Config
**/
void Pin_IN_Config(UWORD Pin);

/**
 * Pin Output Config
**/
void Pin_OUT_Config(UWORD Pin);

/**
 * delay x ms
**/
void Delay_ms(UDOUBLE xms);
void Delay_us(UDOUBLE xus);

/**
 * Module Initialize, initialize the pins, SPI protocol
**/
void Dev_Module_Init();

/**
 * Module exit, reset the pins, reset SPI protocol
**/
void Dev_Module_Exit();

#endif