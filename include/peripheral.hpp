#ifndef PERIPHERAL_HPP
#define PERIPHERAL_HPP

#include "general.hpp"

class Peripheral
{
    protected:
        uint64 beginning_address;
        uint64 end_address;
    
    public:
        Peripheral(int begin, int end);
        virtual void execOrder() = 0;
        virtual std::string getName();
        uint64 getBeginAddr(void);
        uint64 getEndAddr(void);
};

#endif