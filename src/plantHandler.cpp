#include <Arduino.h>
#include "plantHandler.h"
#include "config.h"
using namespace PlantMonitor;

PlantHandler::PlantHandler(/* args */) : plantNumber(0)
{
}

PlantHandler::~PlantHandler()
{
}

void PlantHandler::setup()
{
    pinMode(ENABLE_PIN, OUTPUT);
    addPlant(3, 4);
}

void PlantHandler::read()
{
    if (mBleHandler->isConnected())
    {

        digitalWrite(ENABLE_PIN, HIGH);
        delay(100);
        for (size_t i = 0; i < plantNumber; i++)
        {
            mPlants[i].readValues();
            mBleHandler->writeLigth(mPlants->getLightValue());
            mBleHandler->writeWater(mPlants->getWaterValue());
            Serial.println("Plant");
            Serial.println(i);
            Serial.println(mPlants[i].getLightValue());
            Serial.println(mPlants[i].getWaterValue());
        }
        digitalWrite(ENABLE_PIN, LOW);
    }
}

void PlantHandler::addPlant(int waterPin, int lightPin)
{
    Plant plant;
    plant.setup(waterPin, lightPin);
    mPlants[plantNumber] = plant;
    plantNumber++;
}