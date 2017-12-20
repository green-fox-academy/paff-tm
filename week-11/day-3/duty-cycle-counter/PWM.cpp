#include <string>
#include <sstream>
#include "PWM.h"

using namespace std;

PWM::PWM()
{
    //ctor
}

PWM::~PWM()
{
    //dtor
}

unsigned int PWM::getPeriodCycles()
{
    return period_cycles;
}

unsigned int PWM::getPrescaler()
{
    return prescaler;
}

unsigned int PWM::getOverflow()
{
    return overflow;
}

unsigned int PWM::getDuty()
{
    return duty;
}

void PWM::setPeriodCycles(unsigned int _value)
{
    period_cycles = _value;
}

void PWM::setPrescaler(unsigned int _value)
{
    prescaler = _value;
}

void PWM::setOverflow(unsigned int _value)
{
    overflow = _value;
}

void PWM::setDuty(unsigned int _value)
{
    duty = _value;
}

string PWM::toString()
{
    ostringstream output;
    output << "The PWM has a period of " << period_cycles << " with the duty cycle of " << duty << "." << endl << "The prescaler is " << prescaler << "and the overflow is " << overflow << "." << endl;
    return output.str();
}
