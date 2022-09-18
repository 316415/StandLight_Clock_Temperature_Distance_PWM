#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Service.h"
#include "ClockService.h"
#include "DHT_Data.h"
#include "TempHumidService.h"
#include "ServicePWM.h"

class Controller
{
private:
    int lightState;
    Service *service;
    ClockService *clockService;
    TempHumidService *tempHumidService;
    ServicePWM *servicePWM;

public:
    Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService, ServicePWM *servicePWM);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance, int cnt);
};

#endif /* __CONTROLLER_H__ */