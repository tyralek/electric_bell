#include "BellDriver.hpp"
#include "Gpio.hpp"

BellDriver::BellDriver() :
    _bell_count(0)
{}

void
BellDriver::fire()
{
    _bell_count = BellCount::LONG;
}

void
BellDriver::update()
{
    if (_bell_count > 0)
    {
        _bell_count--;
        Gpio::toggle(Gpio::Port::OUT_LED);
    }
    else
    {
        Gpio::clear(Gpio::Port::OUT_LED);
    }
}
