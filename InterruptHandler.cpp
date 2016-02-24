#include <avr/interrupt.h>
#include <util/delay.h>
#include "InterruptHandler.hpp"

#include "Gpio.hpp"

static InterruptHandler interrupt_handler;

ISR(INT0_vect, ISR_ALIASOF(PCINT0_vect));
ISR(PCINT0_vect)
{
    interrupt_handler.button_flag = true;
    _delay_ms(10);
}

ISR(TIM0_COMPB_vect, ISR_ALIASOF(TIM0_COMPA_vect));
ISR(TIM0_COMPA_vect)
{
    interrupt_handler.timer_flag = true;
//    PINB = 1<<OUT_LED;
}

void InterruptHandler::init()
{
    interrupt_handler.button_flag = false;
    interrupt_handler.timer_flag = false;

    // pull up
    PORTB |= Gpio::Port::IN_BUTTON;
    // select pin change interrupt
    PCMSK = Gpio::Port::IN_BUTTON;
    // enable pin change interrupt
    GIMSK = 1<<PCIE;
    // enable global interrupt
    sei();
}

InterruptHandler& InterruptHandler::get_instance()
{
    return interrupt_handler;
}
