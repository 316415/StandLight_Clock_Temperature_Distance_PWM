#include "ServicePWM.h"

ServicePWM::ServicePWM(ViewPWM *viewPWM)
{
    this->viewPWM = viewPWM;
    PWM_state = PWM_STOP;
    motorState = MOTOR_STOP;
    warning_state = false;
    temp = MOTOR_TEMP;
}

ServicePWM::~ServicePWM()
{

}

void ServicePWM::updateState(std::string strBtn)
{
    switch (PWM_state)
    {
        case PWM_STOP:
            if (strBtn == "PWM_Button")
            {
                PWM_state = PWM_1;
            }

            if (strBtn == "powerButton")
            {
                PWM_state = PWM_STOP;
                motorState = MOTOR_STOP;
            }
            viewPWM->setState(PWM_state);
            break;

        case PWM_1:
            if (strBtn == "PWM_Button")
            {
                PWM_state = PWM_2;
            }

            if (strBtn == "powerButton")
            {
                PWM_state = PWM_STOP;
                motorState = MOTOR_STOP;
            }
            viewPWM->setState(PWM_state);
            break;

        case PWM_2:
            if (strBtn == "PWM_Button")
            {
                PWM_state = PWM_3;
            }

            if (strBtn == "powerButton")
            {
                PWM_state = PWM_STOP;
                motorState = MOTOR_STOP;
            }
            viewPWM->setState(PWM_state);
            break;
        
        case PWM_3:
            if (strBtn == "PWM_Button")
            {
                PWM_state = PWM_STOP;
                motorState = MOTOR_STOP;
            }

            if (strBtn == "powerButton")
            {
                PWM_state = PWM_STOP;
                motorState = MOTOR_STOP;
            }
            viewPWM->setState(PWM_state);
            break;

        case PWM_WARNING:
            if (strBtn == "PWM_Button")
            {
                PWM_state = PWM_STOP;
                motorState = MOTOR_STOP;
            }

            if (strBtn == "powerButton")
            {
                PWM_state = PWM_STOP;
                motorState = MOTOR_STOP;
            }
        viewPWM->setState(PWM_state);
        break;
    }

    switch (motorState)
    {
        case MOTOR_STOP:
            if (strBtn == "motorStateButton")
            {
                if(PWM_state == PWM_STOP)
                {
                    PWM_state = PWM_1;
                }
                motorState = MOTOR_1;
                temp = MOTOR_TEMP;
            }
            break;

        case MOTOR_1:
            if (strBtn == "motorStateButton")
            {
                if(PWM_state == PWM_STOP)
                {
                    PWM_state = PWM_1;
                }
                motorState = MOTOR_2;
                temp = MOTOR_TEMP+1;
            }
            break;

        case MOTOR_2:
            if (strBtn == "motorStateButton")
            {
                if(PWM_state == PWM_STOP)
                {
                    PWM_state = PWM_1;
                }
                motorState = MOTOR_3;
                temp = MOTOR_TEMP+2;
            }
            break;

        case MOTOR_3:
            if (strBtn == "motorStateButton")
            {
                if(PWM_state == PWM_STOP)
                {
                    PWM_state = PWM_1;
                }
                motorState = MOTOR_4;
                temp = MOTOR_TEMP+3;
            }
            break;

        case MOTOR_4:
            if (strBtn == "motorStateButton")
            {
                if(PWM_state == PWM_STOP)
                {
                    PWM_state = PWM_1;
                }
                motorState = MOTOR_STOP;
                temp = MOTOR_TEMP+4;
            }
            break;
        
        case MOTOR_5:
            if (strBtn == "motorStateButton")
            {
                motorState = MOTOR_STOP;
            }
            break;
    }
    printf("motor_state : %d\n", motorState);
    printf("pwm_state : %d\n", PWM_state);
    printf("motor_temp : %d\n", temp);
}

void ServicePWM::updateCount(int cnt)
{
    if(!warning_state)
    {
        if(cnt >= 10)
        {
            viewPWM->setState(PWM_STOP);
        }
        else
        {
            viewPWM->setState(PWM_state);
        }
    }    
}

void ServicePWM::updateTemp(DHT_Data dhtData)
{
    if(dhtData.Temp < WARNING_TEMP)
    {
        warning_state = false;
        if (motorState != MOTOR_STOP)
        {
            if(dhtData.Temp > temp)
            {
                viewPWM->setState(PWM_state);
            }
        }
    }
    else
    {
        warning_state = true;
        viewPWM->setState(PWM_STOP);
    }
}