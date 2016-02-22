#include <avr/io.h>
#include <util/delay.h>

// work plan
// 1. watch-dog
// 2. interrupt
// 3. timer + pwm
// 4. sleep
// 4. out put
// 5. time logic

int main(void)
{
    const int msDelay = 200;

    // PortB pin4 to output (set bit to 1 using SHL)
    DDRB = 1<<DDB3;

    // PortB to low
    PORTB = 0;

    while (1) {
        // XOR on pin 4
        PORTB ^= 1<<PB3;
        _delay_ms(msDelay);
    }

    return 0;
}
