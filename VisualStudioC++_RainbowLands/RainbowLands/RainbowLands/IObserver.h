#pragma once
class IObserver
{
public:
    IObserver() {}
    virtual ~IObserver() {}
    virtual void Notify() = 0;

};