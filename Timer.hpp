#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <avr/io.h>

class Timer
{
public:
    struct ClockSource
    {
        enum _ClockSource
        {
            NONE                = (0<<CS02)|(0<<CS01)|(0<<CS00),
            CLK_IO_DIV_BY_1     = (0<<CS02)|(0<<CS01)|(1<<CS00),
            CLK_IO_DIV_BY_8     = (0<<CS02)|(1<<CS01)|(0<<CS00),
            CLK_IO_DIV_BY_64    = (0<<CS02)|(1<<CS01)|(1<<CS00),
            CLK_IO_DIV_BY_256   = (1<<CS02)|(0<<CS01)|(0<<CS00),
            CLK_IO_DIV_BY_1024  = (1<<CS02)|(0<<CS01)|(1<<CS00),
            EXT_T0_FALLING_EDGE = (1<<CS02)|(1<<CS01)|(0<<CS00),
            EXT_T0_RISING_EDGE  = (1<<CS02)|(1<<CS01)|(1<<CS00),
        };
    };

    struct WaveformMode
    {
        enum _WaveformMode
        {
            TOP                         = (0<<WGM02)|(0<<WGM01)|(0<<WGM00),
            PWM_TOP                     = (0<<WGM02)|(0<<WGM01)|(1<<WGM00),
            CLEAR_TIMER_ON_COMPARE_MATCH= (0<<WGM02)|(1<<WGM01)|(0<<WGM00),
            FAST_PWM_TOP                = (0<<WGM02)|(1<<WGM01)|(1<<WGM00),
            PWM_OCRA                    = (1<<WGM02)|(0<<WGM01)|(1<<WGM00),
            FAST_PWM_OCRA               = (1<<WGM02)|(1<<WGM01)|(1<<WGM00),
        };
    };

    struct Interrupt
    {
        enum _Interrupt
        {
            COMPARE_MATCH_A = 1<<OCIE0A,
            COMPARE_MATCH_B = 1<<OCIE0B,
            TIMER_OVERFLOW  = 1<<TOIE0,
        };
    };

    static inline void waveform(WaveformMode::_WaveformMode waveform) { TCCR0A = waveform; }
    static inline void clock_source(ClockSource::_ClockSource clock) { TCCR0B = clock; }
    static inline void interrupt_enable(Interrupt::_Interrupt mask) { TIMSK0 |= mask; }
    static inline void set_output_compare_a(uint8_t value) { OCR0A = value; }
    static inline void set_output_compare_b(uint8_t value) { OCR0B = value; }
};



#endif /* TIMER_HPP_ */
