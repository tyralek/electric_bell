#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

// work plan
// 1. watch-dog
// 2. interrupt
// 3. timer + pwm
// 4. sleep
// 4. out put
// 5. time logic

int main(void)
{
    const int msDelay = 200;

    led_init();
    while (1) {
        led_toogle();
        _delay_ms(msDelay);
    }

    return 0;
}
