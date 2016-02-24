#ifndef SYSTEMCLOCK_HPP_
#define SYSTEMCLOCK_HPP_

#include <avr/io.h>

class SystemClock
{
public:

    struct Prescaler
    {
        enum _Prescaler
        {
            CLK_DIV_BY_1    = (0<<CLKPS3)|(0<<CLKPS2)|(0<<CLKPS1)|(0<<CLKPS0),
            CLK_DIV_BY_2    = (0<<CLKPS3)|(0<<CLKPS2)|(0<<CLKPS1)|(1<<CLKPS0),
            CLK_DIV_BY_4    = (0<<CLKPS3)|(0<<CLKPS2)|(1<<CLKPS1)|(0<<CLKPS0),
            CLK_DIV_BY_8    = (0<<CLKPS3)|(0<<CLKPS2)|(1<<CLKPS1)|(1<<CLKPS0),
            CLK_DIV_BY_16   = (0<<CLKPS3)|(1<<CLKPS2)|(0<<CLKPS1)|(0<<CLKPS0),
            CLK_DIV_BY_32   = (0<<CLKPS3)|(1<<CLKPS2)|(0<<CLKPS1)|(1<<CLKPS0),
            CLK_DIV_BY_64   = (0<<CLKPS3)|(1<<CLKPS2)|(1<<CLKPS1)|(0<<CLKPS0),
            CLK_DIV_BY_128  = (0<<CLKPS3)|(1<<CLKPS2)|(1<<CLKPS1)|(1<<CLKPS0),
            CLK_DIV_BY_256  = (1<<CLKPS3)|(0<<CLKPS2)|(0<<CLKPS1)|(0<<CLKPS0),
        };
    };

    static inline void prescaler_enable() { CLKPR = 1<<CLKPCE;}
    static inline void prescaler_select(Prescaler::_Prescaler prescaler) { CLKPR = prescaler; }

};



#endif /* SYSTEMCLOCK_HPP_ */
