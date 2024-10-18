#include "../include/peripheral.hpp"

Peripheral::Peripheral(int begin, int end)
{
    this->beginning_address = begin;
    this->end_address = end;
}

std::string Peripheral::getName()
{
    return "Peripheral";
}

uint64 Peripheral::getBeginAddr()
{
    return this->beginning_address;
}

uint64 Peripheral::getEndAddr()
{
    return this->end_address;
}