/*
 * File:   main.c
 * Author: mohda
 * Created on August 5, 2025, 10:29 PM
 * Topic : SPI SLAVE CODE
 */


#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 4000000

void spi_init(void){
    TRISCbits.RC3 = 1;  // SCK
    TRISCbits.RC4 = 1;  // SDI
    TRISCbits.RC5 = 0;  // SDO
    TRISAbits.RA5 = 1;  // SS
    
    SSPCON1 = 0x24;     // no overflow, serial port enable, clk-low, slave mode ss enabled.
    //SSPSTAT = 0x40;
    SSPSTATbits.SMP = 0;    // must clear in slave mode
    SSPSTATbits.CKE = 1;    // active to idle SPI mode 0.
    SSPBUF = 0xA1;          // preload buffer for handshake acknowledge.
}

void main(void) {
    uint8_t SPI_RCV = 0;
    TRISD = 0x00;   // port for segment 
    LATD = 0x00;
    
    spi_init();
    while(1) {
        while(!SSPSTATbits.BF);
        SPI_RCV = SSPBUF;
        
        if(SPI_RCV != 0xAA) { LATD = SPI_RCV; }
    }
}
