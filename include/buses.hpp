#ifndef BUSES_HPP
#define BUSES_HPP

#include "general.hpp"
#include "peripheral.hpp"

// Buses are here to allow communication between CPU and RAM

enum
{
    READ = 0,
    WRITE = 1
};

class Buses
{
    private:
        uint64 dataBus;
        uint64 addressBus;
        uint8 readWritePin;
        uint8 dataSizeBus;
        std::list<Peripheral *> observerList;
    
    public:
        Buses();
        ~Buses();
        uint64 getDataBus(void);
        uint64 getAddressBus(void);
        uint8 getReadWritePin(void);
        uint8 getDataSizeBus(void);
        void setDataBus(uint64 data);
        void setAddressBus(uint64 address);
        void setReadWritePin(uint8 pin);
        void setDataSizeBus(uint8 size);
        void addObserver(Peripheral *p);
        void setBusesAndNotify(uint8 rw, uint64 addr, uint8 size);
        void setBusesAndNotify(uint8 rw, uint64 addr, uint64 data, uint8 size);
        void notifyPeriph(void);
};

#endif