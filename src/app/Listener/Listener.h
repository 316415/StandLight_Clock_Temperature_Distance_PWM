#ifndef __LISTENER_H__
#define __LISTENER_H__

#include <wiringPi.h>
#include "Button.h"
#include "Controller.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"

class Listener
{
private :
    Button *motorStateButton;
    Button *powerButton;
    Button *modeButton;
    Button *stopWatchButton;
    Button *PWM_Button;
    Controller *controller;
    ClockCheck *timeClock;
    DHT11 *dht11;
    UltraSonic *ultraSonic;

public:
    Listener(Button *button, Button *powerButton, Button *stopWatchButton, Button *PWM_Button, Button *motorStateButton, Controller *control, ClockCheck *time, DHT11 *dht11, UltraSonic *ultraSonic);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */
