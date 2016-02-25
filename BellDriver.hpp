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
            LONG = 10,
            SHORT = 2,
        };
    };

    struct TimeCount
    {
        enum _TimeCount
        {
            TO_SECOND = 100,    // Ticks
            TO_SHORT = 30,      // sec
            TO_LONG = 10*60,    // sec
        };
    };

    BellDriver();

    void fire();
    void update();

protected:
    void _update_output();
    void _update_count();

    uint8_t _bell_count;
    uint8_t _to_second_counter;
    uint16_t _second_counter;
};

#endif /* BELLDRIVER_HPP_ */
