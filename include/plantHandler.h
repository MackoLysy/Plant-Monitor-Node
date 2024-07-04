#pragma once
#include <plant.h>
#include "iBleHandler.h"
namespace PlantMonitor
{
    class PlantHandler
    {
    public:
        PlantHandler(/* args */);
        ~PlantHandler();
        void read();
        void setup();
        void bleHandler(IBleHandler *value) { mBleHandler = value; };

    private:
        void addPlant(int waterPin, int lightPin);
        size_t plantNumber;
        Plant mPlants[5];
        IBleHandler *mBleHandler;
    };
}
