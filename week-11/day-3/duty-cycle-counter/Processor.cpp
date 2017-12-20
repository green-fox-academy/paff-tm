#include "Processor.h"

using namespace std;

Processor::Processor()
{
    pwm = getPWMParams(50);
}

Processor::~Processor()
{
    //dtor
}

PWM *Processor::getPWMParams(unsigned int _duty, unsigned int _frequency)
{
    PWM *_pwm_instance = new PWM();

    _pwm_instance->setPeriodCycles(0);
    _pwm_instance->setPrescaler(0);
    _pwm_instance->setDuty((_pwm_instance->getPeriodCycles() + 1) / 2 - 1);
    _pwm_instance->setOverflow(0);

    return _pwm_instance;
}

string Processor::toString()
{
    return pwm->toString();
}
