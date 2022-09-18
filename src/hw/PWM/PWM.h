#ifndef PWM_H
#define PWM_H

#pragma once
#include <wiringPi.h>
#include <softPwm.h>

class PWM
{
public:
    PWM(int pin);
    virtual ~PWM();
    void powerPWM(int dutyCyle);
    void stopPWM();

private:
    int pinNum;
    int power_PWM;
};

#endif