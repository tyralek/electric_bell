#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <avr/io.h>

class Gpio
{
public:
    struct Port
    {
        enum _Port
        {
            OUT_BELL = 1<<PB3,
            IN_BUTTON = 1<<PB4,
        };
    };

    struct Interrupt
    {
        enum _Interrupt
        {
            EXTERNAL_INT0   = 1<<INT0,
            PIN_CHANGE      = 1<<PCIE,
        };
    };

    // set as input with pull up
    static inline void as_input(Port::_Port port) { DDRB &= ~port; PORTB |= port; }
    static inline void as_output(Port::_Port port) { DDRB |= port; }

    static inline void set(Port::_Port port) { PORTB |= port; }
    static inline void clear(Port::_Port port) { PORTB &= ~port; }
    static inline void toggle(Port::_Port port) { PINB = port; }

    static inline void interrupt_enable(Interrupt::_Interrupt mask) { GIMSK |= mask; }
    static inline void pin_change_interrupt_source(Port::_Port port) { PCMSK |= port; }
};


#endif /* GPIO_HPP_ */
