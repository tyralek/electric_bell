#ifndef INTERRUPTHANDLER_HPP_
#define INTERRUPTHANDLER_HPP_


class InterruptHandler
{
public:
    void init();
    static InterruptHandler& get_instance();
    bool button_flag;
    bool timer_flag;
};


#endif /* INTERRUPTHANDLER_HPP_ */
