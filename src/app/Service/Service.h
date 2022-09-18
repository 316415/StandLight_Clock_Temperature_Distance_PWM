#ifndef SERVICE_H
#define SERVICE_H

#include "LightState.h"
#include "View.h"
#include "DHT_Data.h"
#include "Temp.h"
#pragma once

class Service
{
public:
    Service(View *viewer);
    virtual ~Service();
    void updateState(std::string strState);
    void updateDistance(int distance, int cnt);
    void updateTempHumid(DHT_Data dhtData);

private:
    int lightState;
    View *view;
    bool isLightDistance;
    bool warning_state;
};

#endif