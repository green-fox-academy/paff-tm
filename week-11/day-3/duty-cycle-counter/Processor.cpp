#include "Processor.h"

#define CLOCK_CYCLES_PER_SECOND  72000000
#define MAX_RELOAD               0xFFFF

using namespace std;

Processor::Processor()
{
    pwm = getPWMParams(50);
}

Processor::~Processor()
{
    delete pwm;
}

PWM *Processor::getPWMParams(unsigned int _duty, unsigned int _frequency)
{
    PWM *_pwm_instance = new PWM();

    _pwm_instance->setPeriodCycles(CLOCK_CYCLES_PER_SECOND / _frequency);
    _pwm_instance->setPrescaler(_pwm_instance->getPeriodCycles() / MAX_RELOAD + 1);
    _pwm_instance->setOverflow((_pwm_instance->getPeriodCycles() + (_pwm_instance->getPrescaler() / 2)) / _pwm_instance->getPrescaler());
    _pwm_instance->setDuty((_pwm_instance->getPeriodCycles() + 1) / (100 / _duty) - 1);

    return _pwm_instance;
}

string Processor::toString()
{
    return pwm->toString();
}
