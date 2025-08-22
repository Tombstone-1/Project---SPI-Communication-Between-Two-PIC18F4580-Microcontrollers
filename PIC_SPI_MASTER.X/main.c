/*
 * File:   main.c
 * Author: mohda
 * Created on August 5, 2025, 9:29 PM
 * Topic : SPI master code.
 */

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 4000000
#define SS_PIN LATAbits.LATA5

uint8_t cathode_hex[]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void spi_init(void) {
    TRISCbits.RC3 = 0;  // SCK
    TRISCbits.RC4 = 1;  // SDI
    TRISCbits.RC5 = 0;  // SDO
    TRISAbits.RA5 = 0;  // SS
    
    SSPCON1 = 0x20;     // SPI port enabled, clock idle low level, master mode fosc/4.
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 1;    // SPI mode - 0, active to idle
    SS_PIN = 1;
}

void spi_ack(uint8_t data) {
    uint8_t ack = 0;
    SSPBUF = data;
    while(!SSPSTATbits.BF);
    ack = SSPBUF;
    if (ack == 0xA1) { LATDbits.LATD0 = 1; }
}

void spi_write(uint8_t data) {
    SSPBUF = data;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
}
void main(void) {
    uint8_t i=0;
    TRISDbits.RD0 = 0;
    spi_init();
    
    while(1) {
        SS_PIN = 0;
        spi_ack(0xAA);
        
        for(i=0; i<10; i++){
            spi_write(cathode_hex[i]);
            __delay_ms(1000);
        }
        LATDbits.LATD0 = 0;
        SS_PIN = 1;
        __delay_ms(2000);
    }
}
