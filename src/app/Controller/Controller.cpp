#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService, ServicePWM *servicePWM)
{
    service = serv;
    clockService = clockServ;
    lightState = LIGHT_OFF;
    this->tempHumidService = tempHumidService;
    this->servicePWM = servicePWM;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
        servicePWM->updateState("powerButton");
    }

    if (strBtn == "stopWatchButton")
    {
        clockService->updateCount("stopWatchButton");
    }

    if (strBtn == "PWM_Button")
    {
        servicePWM->updateState("PWM_Button");
    }

    if (strBtn == "motorStateButton")
    {
        servicePWM->updateState("motorStateButton");
    }

    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }

}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    service->updateTempHumid(dhtData);
    tempHumidService->updateEvent(dhtData);
    servicePWM->updateTemp(dhtData);
}

void Controller::updateDistance(int distance, int cnt)
{
    service->updateDistance(distance, cnt);
    servicePWM->updateCount(cnt);
}