#pragma once
#include <SPI.h>
#include <BLEPeripheral.h>
#include "iBleHandler.h"
namespace PlantMonitor
{
    class BleHandler : public IBleHandler
    {

    public:
        BleHandler(/* args */);
        ~BleHandler();
        void poll();
        void setupPeripherial();
        void writeWater(uint32_t val) override;
        void writeLigth(uint32_t val) override;
        bool isConnected() override;

    private:
        static BleHandler *mInstance;
        BLEService *mPlantService;
        BLEPeripheral *mblePeripherial;
        BLEDescriptor *mPlantDescriptor;
        BLECharacteristic *mPlantCharacteristics;
        static void blePeripheralConnectHandler(BLECentral &central);
        static void blePeripheralDisconnectHandler(BLECentral &central);
        static void bleDiscovered(BLECentral &central);
    };
}
