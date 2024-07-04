#pragma once

class IBleHandler
{
public:
    IBleHandler(){};
    virtual ~IBleHandler(){};
    virtual void writeWater(uint32_t val) = 0;
    virtual void writeLigth(uint32_t val) = 0;
    virtual bool isConnected() = 0;
};