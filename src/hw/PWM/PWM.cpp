#include "PWM.h"

PWM::PWM(int pin)
{
    pinNum = pin;
    wiringPiSetup();
    softPwmCreate(pinNum, 0, 100);
}

PWM::~PWM()
{

}

void PWM::powerPWM(int dutyCyle)
{
    power_PWM = dutyCyle;
    softPwmWrite(pinNum, power_PWM);
}

void PWM::stopPWM()
{
    softPwmWrite(pinNum, 0);
}