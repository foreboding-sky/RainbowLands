#pragma once
#include "IObserver.h"
#include <vector>

enum Message
{
    ENEMY_DIED,
    DAMAGE_TAKEN,
    WAVE_STARTED,
    TOWER_SPAWNED
};

class ISubject
{
private:
    std::vector<IObserver*> observers;
public:
    ISubject() {}
    virtual ~ISubject() {}
    void AttachObserver(IObserver *o)
    {
        observers.push_back(o);
    }
    void DetachObserver(IObserver* o)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), o));
    }
    void Notify(Message msg)
    {
        for (auto* o : observers) {
            o->Update(msg);
        }
    }
};