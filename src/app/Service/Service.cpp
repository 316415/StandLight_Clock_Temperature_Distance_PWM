#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    isLightDistance = false;
    warning_state = false;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton")
            {
                lightState = LIGHT_1;
            }
            if (strState == "powerButton")
            {
                lightState = LIGHT_OFF;  
            }
            view->setState(lightState);
        break;

        case LIGHT_1:
            if (strState == "modeButton")
            {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton")
            {
                lightState = LIGHT_OFF;  
            }
            view->setState(lightState);
        break;
        
        case LIGHT_2:
            if (strState == "modeButton")
            {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton")
            {
                lightState = LIGHT_OFF;  
            }
            view->setState(lightState);
        break;

        case LIGHT_3:
            if (strState == "modeButton")
            {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton")
            {
                lightState = LIGHT_OFF;  
            }
            view->setState(lightState);
        break;

        case LIGHT_4:
            if (strState == "modeButton")
            {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton")
            {
                lightState = LIGHT_OFF;  
            }
            view->setState(lightState);
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton")
            {
                lightState = LIGHT_OFF;  
            }
            //if(거리 범위 이내) --> 켜짐. else 꺼지는데 상태는 저장한 채로
            if (isLightDistance)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
            
        break;

        case WARNING:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton")
            {
                lightState = LIGHT_OFF;  
            }
            view->setState(lightState);
        break;        
    }
}

void Service::updateTempHumid(DHT_Data dhtData)
{
    if(dhtData.Temp < WARNING_TEMP)
    {
        warning_state = false;
    }
    else
    {
        warning_state = true;
    }
}

#if 1
void Service::updateDistance(int distance, int cnt)
{
    if(!warning_state)
    {
        if(cnt >= 10)
        {
            //light off
            isLightDistance = false;
            view->setState(LIGHT_OFF);
        }
        else
        {
            //light on
            isLightDistance = true;
            view->setState(lightState);
        }
    }
    else
    {
        view->setState(WARNING);
    }

    printf("distance : %d, bool : %d, cnt : %d\n", distance, isLightDistance, cnt);
}
#else //교수님 코드
static int distanceOffCounter;
void Service::updateDistance(int distance)
{
    if(distance < 0)
    {
        distanceOffCounter++;
        if(distanceOffCounter >= 10)
        {
            //light off
            isLightDistance = false;
            view->setState(LIGHT_OFF);
        }
    }
    else
    {
        //light on
        distanceOffCounter = 0;
        isLightDistance = true;
        view->setState(lightState);
    }

    printf("distance : %d, bool : %d, cnt : %d\n", distance, isLightDistance, distanceOffCounter);
}
#endif