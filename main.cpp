#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// work plan
// 1. watch-dog
// 2. interrupt ok
// 3. timer + pwm
// 4. sleep
// 4. out put
// 5. time logic

#define OUT_LED PB3
#define IN_BUTTON PB4

ISR(INT0_vect, ISR_ALIASOF(PCINT0_vect));
ISR(PCINT0_vect)
{
    PINB = 1<<OUT_LED;
    _delay_ms(10);
}


int main(void)
{
    // pull up
    PORTB |= (1<<IN_BUTTON);
    // enable on PB4
    PCMSK = 1<<IN_BUTTON;
    // enable pin change interrupt
    GIMSK = 1<<PCIE;
    // enable global interrupt
    sei();

    DDRB = 1<<DDB3;
    while (1)
    {
        _delay_ms(500);
    }

    return 0;
}
