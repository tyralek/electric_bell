#include <avr/sleep.h>
#include "SystemClock.hpp"
#include "Gpio.hpp"
#include "Timer.hpp"
#include "InterruptHandler.hpp"

// work plan
// 1. watch-dog
// 5. time logic


int main(void)
{
    SystemClock::prescaler_enable();
    SystemClock::prescaler_select(SystemClock::Prescaler::CLK_DIV_BY_64);

    Gpio::as_output(Gpio::Port::OUT_LED);
    Gpio::as_input(Gpio::Port::IN_BUTTON);
    Gpio::pin_change_interrupt_source(Gpio::Port::IN_BUTTON);
    Gpio::interrupt_enable(Gpio::Interrupt::PIN_CHANGE);

    // 50Hz = 9600000Hz/1024/x
    // x = 9600000Hz/1024/50
    const uint8_t COMPARE_VALUE= 96000000UL/1024/50;
    Timer::set_output_compare_a(COMPARE_VALUE);
    Timer::waveform(Timer::WaveformMode::CLEAR_TIMER_ON_COMPARE_MATCH);
    Timer::interrupt_enable(Timer::Interrupt::COMPARE_MATCH_A);
    Timer::clock_source(Timer::ClockSource::CLK_IO_DIV_BY_1024);

    InterruptHandler& interrupt_handler = InterruptHandler::get_instance();
    interrupt_handler.init();
    interrupt_handler.enable();

    set_sleep_mode(SLEEP_MODE_IDLE);
    while (1)
    {
        sleep_enable();
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
