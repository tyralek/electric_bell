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
        _delay_ms(10);
    }

    return 0;
}
