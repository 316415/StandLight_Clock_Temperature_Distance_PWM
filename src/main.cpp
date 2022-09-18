#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "TempHumidService.h"
#include "TempHumidView.h"
#include "PWM.h"
#include "ServicePWM.h"
#include "ViewPWM.h"
#include <time.h>

int main()
{
    std::cout << "Hello World!" << std::endl;
    // time_t timeSec;
    // struct tm *timeDate;

    ClockCheck clockCheck;
    Button motorStateButton(6);
    Button PWM_Button(26);
    Button modeButton(27);
    Button powerButton(28);
    Button stopWatchButton(29);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    DHT_Data dhtData;
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    UltraSonic ultraSonic(5,4);
    PWM PWM(1);

    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockView(&lcd);
    TempHumidView tempHumidView(&lcd, &led1, &led2, &led3, &led4, &led5);
    ViewPWM viewPWM(&PWM);

    Service service(&view);
    ClockService clockService(&clockView);
    TempHumidService tempHumidService(&tempHumidView);
    ServicePWM servicePWM(&viewPWM);
    
    Controller control(&service, &clockService, &tempHumidService, &servicePWM);
    Listener listener(&modeButton, &powerButton, &stopWatchButton, &PWM_Button, &motorStateButton, &control, &clockCheck, &dht, &ultraSonic);
    
    while (1)
    {
        // dhtData = dht.readData();
        // if(!dhtData.error)
        // {
        //     std::cout << "humidity : " << dhtData.RH
        //     << "." << dhtData.RHDec
        //     << "%, Temperature : " << dhtData.Temp <<
        //     "." << dhtData.TempDec << "C" << std::endl;
        // }
        listener.checkEvent();
        view.lightView();
        delay(10);
    }

    return 0;
}