#include <avr/io.h>
#include "led.h"

void led_init()
{
    DDRB = 1<<DDB3;
    PORTB = 0;

}

void led_on()
{

}

void led_off()
{

}

void led_toogle()
{
    PINB = 1<<PIN3;
}
