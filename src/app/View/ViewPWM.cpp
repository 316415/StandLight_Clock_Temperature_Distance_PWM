#include "ViewPWM.h"

ViewPWM::ViewPWM(PWM *pwm)
{
    this->pwm = pwm;
}

ViewPWM::~ViewPWM()
{

}

void ViewPWM::setState(int PWM_state)
{
    switch (PWM_state)
    {
    case PWM_STOP:
        pwm->stopPWM();
        break;

    case PWM_1:
        pwm->powerPWM(30);
        break;
    
    case PWM_2:
        pwm->powerPWM(60);
        break;

    case PWM_3:
        pwm->powerPWM(90);
        break;

    case PWM_WARNING:
    break;
    }
}