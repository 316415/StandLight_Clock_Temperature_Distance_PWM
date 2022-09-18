#include "ClockService.h"

ClockService::ClockService(ClockView *clockview)
{
    clockState = 0;
    curTime = 0;
    prevTime = 0;
    clockView = clockview;
}

ClockService::~ClockService()
{

}

void ClockService::updateEvent()
{
    if(clockState == 0)
    {
        curTime = time(NULL);
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }

    if(clockState == 1)
    {
        curTime = time(NULL) - prevTime;
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }

    if(clockState == 2)
    {
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }
}

void ClockService::updateCount(std::string strState)
{
    switch(clockState)
    {
        case 0:
            if (strState == "stopWatchButton")
            {
                prevTime = time(NULL)+32401;
                clockState = 1;
            }
        break;
        case 1:
            if (strState == "stopWatchButton")
            {
                prevTime = curTime;
                clockState = 2;
            }
        break;
        case 2:
            if (strState == "stopWatchButton")
            {
                clockState = 0;
            }
        break;
    }
}