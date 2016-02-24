/*
 * GpioPB.h
 *
 *  Created on: 23 lut 2016
 *      Author: tyrala
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <avr/io.h>

class Gpio
{
public:
    struct Port
    {
        enum
        {
            OUT_LED = 1<<PB3,
            IN_BUTTON = 1<<PB4,
        };
    };
    
    static void as_output(uint8_t pin_mask)
    {
        DDRB = pin_mask;
    }

    static void set(uint8_t pin_mask)
    {
        PORTB |= pin_mask;
    }

    static void clear(uint8_t pin_mask)
    {
        PORTB &= ~pin_mask;
    }

    static void toggle(uint8_t pin_mask)
    {
        PINB = pin_mask;
    }
};


#endif /* GPIO_HPP_ */
