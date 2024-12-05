#include <Arduino.h>

u8 lastVal = 0;
u8 i = 0;

void setup() {
    DDRA = 64;
    PORTA = 72;

    DDRB = 0xFF;
    PORTB = 0x00;
}

void loop() {
    u8 currentVal = PINA & 8;
    if((!currentVal) && lastVal) {
        PORTA ^= 64;
    }
    lastVal = currentVal;

    if(PORTA & 64) {
        PORTB = 1<<i;
        if(i == 8) {
            i = 0;
        } else {
            i++;
        }
    } else {
        PORTB |= 1<<i;
        if(i == 8) {
            PORTB = 0;
            i = 0;
        } else {
            i++;
        }
    }
    _delay_ms(500);
}