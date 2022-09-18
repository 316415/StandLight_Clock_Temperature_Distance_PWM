#ifndef SERVICEPWM_H
#define SERVICEPWM_H

#pragma once

#include <string>
#include "DHT_Data.h"
#include "ViewPWM.h"
#include "Temp.h"
#include "PWM_state.h"

class ServicePWM
{
public:
    ServicePWM(ViewPWM *viewPWM);
    virtual ~ServicePWM();

    void updateState(std::string strBtn);
    void updateCount(int cnt);
    void updateTemp(DHT_Data dhtData);

private:
    ViewPWM *viewPWM;
    int PWM_state;
    int motorState;
    int warning_state;
    int temp;
};

#endif