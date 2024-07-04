#include <Arduino.h>

#include "bleHandler.h"
#include "config.h"
using namespace PlantMonitor;
BleHandler::BleHandler(/* args */)
{
    mblePeripherial = new BLEPeripheral();
    mPlantService = new BLEService("AAA0");
    mPlantDescriptor = new BLEDescriptor("2137", "Plant Name");
    mPlantCharacteristics = new BLECharacteristic("AAA2", BLERead | BLENotify, 100);

    // mLedChar = new BLECharCharacteristic("19b10000e8f2537e4f6cd104768a1214", BLERead | BLEWrite | BLENotify);
}

BleHandler::~BleHandler()
{
    delete mblePeripherial;
    delete mPlantService;
    delete mPlantDescriptor;
    delete mPlantCharacteristics;
}

void BleHandler::poll()
{
    mblePeripherial->poll();
}

void BleHandler::writeWater(uint32_t val)
{
    String tempVal(val);
    Serial.write(mPlantCharacteristics->uuid());
    mPlantCharacteristics->setValue("super wiadomosc");
}
void BleHandler::writeLigth(uint32_t val)
{
    String tempVal(val);
}

bool BleHandler::isConnected()
{
    return mblePeripherial->connected();
}

void BleHandler::setupPeripherial()
{
    mblePeripherial->setLocalName(BLE_NAME);
    mblePeripherial->setDeviceName(BLE_NAME);
    mblePeripherial->setEventHandler(BLEConnected, BleHandler::blePeripheralConnectHandler);
    mblePeripherial->setEventHandler(BLEDisconnected, BleHandler::blePeripheralDisconnectHandler);
    mblePeripherial->setAdvertisedServiceUuid(mPlantService->uuid());
    mblePeripherial->addAttribute(*mPlantService);
    mblePeripherial->addAttribute(*mPlantDescriptor);
    mblePeripherial->addAttribute(*mPlantCharacteristics);

    mblePeripherial->begin();
    Serial.println(F("BLE LED Peripheral"));
}

void BleHandler::blePeripheralConnectHandler(BLECentral &central)
{
    Serial.println("Connected!");
}
void BleHandler::blePeripheralDisconnectHandler(BLECentral &central)
{
    Serial.println("Diconnected!");
}
