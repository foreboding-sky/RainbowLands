#pragma once
class IObserver
{
public:
    IObserver() {}
    virtual ~IObserver() {}
    virtual void Notify() = 0;    // "= 0" part makes this method pure virtual, and

};