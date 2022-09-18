#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#include <time.h>
#include "ClockView.h"
#include "Temp.h"

#pragma once

class ClockService
{
public:
    ClockService(ClockView *clockview);
    virtual ~ClockService();
    void updateEvent();
    void updateCount(std::string strState);

private:
    int clockState;
    time_t curTime;
    time_t prevTime;
    ClockView *clockView; //clockView에게 메세지를 전달할 게 필요함
};

#endif