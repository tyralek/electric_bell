#include "Gpio.hpp"
#include "InterruptHandler.hpp"

static InterruptHandler interrupt_handler;

ISR(INT0_vect, ISR_ALIASOF(PCINT0_vect));
ISR(PCINT0_vect)
{
    interrupt_handler.set_button_flag(true);
}

ISR(TIM0_COMPB_vect, ISR_ALIASOF(TIM0_OVF_vect));
ISR(TIM0_COMPA_vect, ISR_ALIASOF(TIM0_OVF_vect));
ISR(TIM0_OVF_vect)
{
    interrupt_handler.set_timer_flag(true);
}

void InterruptHandler::init()
{
    interrupt_handler.set_button_flag(false);
    interrupt_handler.set_timer_flag(false);

    // pull up
    PORTB |= Gpio::Port::IN_BUTTON;
    // select pin change interrupt
    PCMSK = Gpio::Port::IN_BUTTON;
    // enable pin change interrupt
    GIMSK = 1<<PCIE;
}

InterruptHandler& InterruptHandler::get_instance()
{
    return interrupt_handler;
}
