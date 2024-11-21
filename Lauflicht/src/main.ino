#include <Arduino.h>

int i = 0;

void setup() {
    DDRA = 0xFF;
    DDRC = 0x00;
    PORTC = 0x01;
}

void loop() {
    if(PINC & 0x01) {
        if(i > 7) {
            i = 0;
        }
        PORTA = 1 << i;
        _delay_ms(500);
        i++;
    } else {
        if(i > 7) {
            i = 0;
            PORTA = 0x00;
        }
        PORTA |= 1 << i;
        _delay_ms(500);
        i++;
    }
}