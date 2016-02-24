#include <util/delay.h>

#include "Gpio.hpp"
#include "InterruptHandler.hpp"

// work plan
// 1. watch-dog
// 2. interrupt ok
// 3. timer + pwm
// 4. sleep
// 4. out put
// 5. time logic


int main(void)
{
    // set clock prescaler
    CLKPR = 1<<CLKPCE;
    CLKPR = 1<<CLKPS0;

    // number to count up to (0x70 = 112)
//    OCR0A  = 0xfe;
    // Clear Timer on Compare Match (CTC) mode
//    TCCR0A = 0x02;
    // clear interrupt flag
//    TIFR0 |= 0x01;
    // TC0 compare match A interrupt enable
//    TIMSK0 = 0x01;
    // enable timer overflow interrupt
    TIMSK0 = 1<<TOIE0;
    // clock source CLK/1024, start timer
    TCCR0B = 0x05;

    InterruptHandler& interrupt_handler = InterruptHandler::get_instance();
    interrupt_handler.init();

    Gpio::as_output(Gpio::Port::OUT_LED);
    while (1)
    {
        if (interrupt_handler.get_button_flag())
        {
            interrupt_handler.set_button_flag(false);
            Gpio::toggle(Gpio::Port::OUT_LED);
        }

        if (interrupt_handler.get_timer_flag())
        {
            interrupt_handler.set_timer_flag(false);
            Gpio::toggle(Gpio::Port::OUT_LED);
        }

        _delay_ms(10);
    }

    return 0;
}
