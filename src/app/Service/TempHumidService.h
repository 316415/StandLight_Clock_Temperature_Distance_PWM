#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#pragma once
#include "DHT_Data.h"
#include "TempHumidView.h"
#include "Temp.h"

class TempHumidService
{
public:
    TempHumidService(TempHumidView *tempHumidView);
    virtual ~TempHumidService();
    void updateEvent(DHT_Data dhtData);
    void SafetyCheck(float temp, float humid);

private:
    TempHumidView *tempHumidView;
};

#endif