#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "PWM.h"

class Processor
{
    public:
        Processor();
        ~Processor();

        PWM *getPWMParams(unsigned int _duty, unsigned int _frequency = 250);
        string toString();

    private:

        PWM *pwm;
};

#endif // PROCESSOR_H
