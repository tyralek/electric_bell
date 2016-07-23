#ifndef BELLDRIVER_HPP_
#define BELLDRIVER_HPP_
#include <stdint.h>

class BellDriver
{
public:
    struct BellCount
    {
        enum _BellCount
        {
            LONG = 3,
            SHORT = 1,
        };
    };

    struct TimeCount
    {
        enum _TimeCount
        {
            TO_SHORT = 5,       // 5 sec
            TO_LONG = 10*60,    // 10 min
        };
    };

    BellDriver();

    void fire();
    void update();

protected:
    void _update_output();
    void _update_count();

    uint8_t _bell_count;
    uint16_t _second_counter;
};

#endif /* BELLDRIVER_HPP_ */
