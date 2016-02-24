#ifndef INTERRUPTHANDLER_HPP_
#define INTERRUPTHANDLER_HPP_
#include <avr/interrupt.h>

class InterruptHandler
{
public:
    static InterruptHandler& get_instance();
    void init();
    void static enable() { sei(); }
    void static disable() { cli(); }

    bool inline get_button_flag() { return _button_flag; }
    void inline set_button_flag(bool flag) { _button_flag = flag; }

    bool inline get_timer_flag() { return _timer_flag; }
    void inline set_timer_flag(bool flag) { _timer_flag = flag; }

protected:
    bool _button_flag;
    bool _timer_flag;
};

#endif /* INTERRUPTHANDLER_HPP_ */
