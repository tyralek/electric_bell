#include <avr/sleep.h>
#include "Gpio.hpp"
#include "Timer.hpp"
#include "InterruptHandler.hpp"

// work plan
// 1. watch-dog
// 5. time logic


int main(void)
{
    // set clock prescaler
    CLKPR = 1<<CLKPCE;
    CLKPR = 1<<CLKPS0;

    Timer::set_output_compare_a(0xff);
    Timer::interrupt_enable(Timer::Interrupt::COMPARE_MATCH_A);
    Timer::waveform(Timer::WaveformMode::CLEAR_TIMER_ON_COMPARE_MATCH);
    Timer::clock_source(Timer::ClockSource::CLK_IO_DIV_BY_1024);

    Gpio::as_output(Gpio::Port::OUT_LED);

    InterruptHandler& interrupt_handler = InterruptHandler::get_instance();
    interrupt_handler.init();
    set_sleep_mode(SLEEP_MODE_IDLE);
    while (1)
    {
        sleep_enable();
        interrupt_handler.enable();
        sleep_cpu();
        sleep_disable();

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

    }

    return 0;
}
