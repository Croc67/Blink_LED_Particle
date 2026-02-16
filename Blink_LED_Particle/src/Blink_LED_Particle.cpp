// Include Particle Device OS APIs
#include "Particle.h"

const pin_t MY_LED = D7;

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

// Morse timing (in milliseconds)
const int DOT = 200;        // 1 unit
const int DASH = DOT * 3;   // 3 units
const int SYMBOL_SPACE = DOT;        // space between dots/dashes
const int LETTER_SPACE = DOT * 3;    // space between letters
const int WORD_SPACE = DOT * 7;      // space between words

void dot() {
    digitalWrite(MY_LED, HIGH);
    delay(DOT);
    digitalWrite(MY_LED, LOW);
    delay(SYMBOL_SPACE);
}

void dash() {
    digitalWrite(MY_LED, HIGH);
    delay(DASH);
    digitalWrite(MY_LED, LOW);
    delay(SYMBOL_SPACE);
}

void setup() {
    pinMode(MY_LED, OUTPUT);
}

void loop() {

    // S: ...
    dot();
    dot();
    dot();
    delay(LETTER_SPACE);

    // O: ---
    dash();
    dash();
    dash();
    delay(LETTER_SPACE);

    // S: ...
    dot();
    dot();
    dot();
    delay(WORD_SPACE); // pause before repeating
}
