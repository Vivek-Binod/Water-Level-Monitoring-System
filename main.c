#include <lpc213x.h>

#define L1      (1<<0)    // P0.0
#define L2      (1<<1)    // P0.1
#define L3      (1<<2)    // P0.2
#define L4      (1<<3)    // P0.3

#define BUZZER  (1<<4)    // P0.4

#define LED1    (1<<15)   // P0.15
#define LED2    (1<<14)   // P0.14
#define LED3    (1<<13)   // P0.13
#define LED4    (1<<12)   // P0.12

void delay_ms(unsigned int count)
{
    unsigned int i, j;
    for(i = 0; i < count; i++)
        for(j = 0; j < 6000; j++);
}

int main(void)
{
    unsigned int level, s;

    PINSEL0 = 0x00000000;

    IODIR0 |= LED1 | LED2 | LED3 | LED4 | BUZZER;
    IODIR0 &= ~(L1 | L2 | L3 | L4);

    IOCLR0 = LED1 | LED2 | LED3 | LED4 | BUZZER;

    while(1)
    {
        level = IOPIN0 & (L1 | L2 | L3 | L4);
        s = level & 0x0F;

        IOCLR0 = LED1 | LED2 | LED3 | LED4 | BUZZER;

        switch(s)
        {
            case 0x00:
                IOSET0 = BUZZER;
                break;

            case 0x01:
                IOSET0 = LED1 | BUZZER ;
                break;

            case 0x03:
                IOSET0 = LED1 | LED2;
                break;

            case 0x07:
                IOSET0 = LED1 | LED2 | LED3;
                break;

            case 0x0F:
                IOSET0 = LED1 | LED2 | LED3 | LED4;
                break;

            default:
                IOSET0 = BUZZER;
                break;
        }

        delay_ms(50);
    }
}