#ifndef PWM_H
#define PWM_H

#include <string>

class PWM
{
    public:
        PWM();
        ~PWM();
        unsigned int getPeriodCycles();
        unsigned int getPrescaler();
        unsigned int getOverflow();
        unsigned int getDuty();
        void setPeriodCycles(unsigned int _value);
        void setPrescaler(unsigned int _value);
        void setOverflow(unsigned int _value);
        void setDuty(unsigned int _value);

        string getString();

    protected:

    private:
        unsigned int period_cycles;
        unsigned int prescaler;
        unsigned int overflow;
        unsigned int duty;
};

#endif // PWM_H
