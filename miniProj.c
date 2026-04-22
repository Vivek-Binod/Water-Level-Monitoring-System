#include <reg51.h>

sbit L1 = P1^0;
sbit L2 = P1^1;
sbit L3 = P1^2;
sbit L4 = P1^3;

sbit LED1   = P2^0;
sbit LED2   = P2^1;
sbit LED3   = P2^2;
sbit LED4   = P2^3;
sbit BUZZER = P2^4;

void delay(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 120; j++); 
}

void main() {
    P1 = 0xFF; 
    P2 = 0x00; 

    while(1) {
        unsigned char status = ~(P1) & 0x0F; 

        P2 = 0x00;

        switch(status) {
            case 0x00: 
                BUZZER = 1; 
                break;

            case 0x01: 
                LED1 = 1;
                BUZZER = 1; 
                break;

            case 0x03: 
                LED1 = 1;
                LED2 = 1;
                BUZZER = 0; 
                break;

            case 0x07: 
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                break;

            case 0x0F: 
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 1;
                break;

            default:   
                BUZZER = 1;
                break;
        }
        delay(50); 
    }
}