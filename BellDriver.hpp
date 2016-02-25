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

    BellDriver();

    void fire();
    void update();

protected:
    uint8_t _bell_count;
};

#endif /* BELLDRIVER_HPP_ */
