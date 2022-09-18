#include "Listener.h"
#include <wiringPi.h>

Listener::Listener(Button *button, Button *powerButton, Button *stopWatchButton, Button *PWM_Button, Button *motorStateButton, Controller *control, ClockCheck *time, DHT11 *dht11, UltraSonic *ultraSonic)
{
    modeButton = button;
    this->powerButton = powerButton;
    this->stopWatchButton = stopWatchButton;
    this->PWM_Button = PWM_Button;
    this->motorStateButton = motorStateButton;
    controller = control;
    timeClock = time;
    this->dht11 = dht11;
    this->ultraSonic = ultraSonic;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (stopWatchButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("stopWatchButton");
    }

    if (PWM_Button->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("PWM_Button");
    }

    if (motorStateButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("motorStateButton");
    }

    if (timeClock->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime > 2000)
    {
        DHT_Data dhtData = dht11->readData();
        prevTempHumidTime = millis();
        if(dhtData.error == 0)
        {
            controller->updateTempHumid(dhtData);
        }
    }
    
    static unsigned int prevUltraSonicTime = 0;
    static int cnt= 0;
    if(millis() - prevUltraSonicTime > 1000)
    {
        prevUltraSonicTime = millis();
        int distance = ultraSonic->readDistance();
        if(distance < 0)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        controller->updateDistance(distance, cnt);
        
    }
    
}