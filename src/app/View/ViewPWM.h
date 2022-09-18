#ifndef VIEWPWM_H
#define VIEWPWM_H

#pragma once
#include "PWM.h"
#include "PWM_state.h"

class ViewPWM
{
public:
    ViewPWM(PWM *pwm);
    ~ViewPWM();

    void setState(int PWM_state);

private:
    PWM *pwm;
};

#endif