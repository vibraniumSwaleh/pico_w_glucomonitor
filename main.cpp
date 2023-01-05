#include <iostream>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "SPI_Config.h"

int main(){
      
    Dev_Module_Init();
    
    cout << " We are setting up SPI ...\n";
    
    return 0;
}