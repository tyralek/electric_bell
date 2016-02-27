#include "BellDriver.hpp"
#include "Gpio.hpp"

BellDriver::BellDriver() :
    _bell_count(0),
    _to_second_counter(TimeCount::TO_SECOND),
    _second_counter(TimeCount::TO_LONG)
{}

void
BellDriver::fire()
{
    if (_second_counter >= TimeCount::TO_LONG)
    {
        _bell_count = BellCount::LONG;
        _second_counter = 0;
    }
    else if (_second_counter >= TimeCount::TO_SHORT)
    {
        _bell_count = BellCount::SHORT;
        _second_counter = 0;
    }
}

void
BellDriver::update()
{
    _update_output();
    _update_count();
}

void
BellDriver::_update_output()
{
    if (_bell_count > 0)
    {
        _bell_count--;
        Gpio::toggle(Gpio::Port::OUT_BELL);
    }
    else
    {
        Gpio::clear(Gpio::Port::OUT_BELL);
    }
}

void
BellDriver::_update_count()
{
    _to_second_counter--;
    if (_to_second_counter == 0)
    {
        _to_second_counter = TimeCount::TO_SECOND;
        _second_counter++;
    }
}
