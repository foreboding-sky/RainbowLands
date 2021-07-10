#pragma once
#include "IObserver.h"
#include <vector>

enum Message
{
    SCORE_GAINED,
    GOLD_GAINED,
    DAMAGE_TAKEN,
    WAVE_STARTED,
    TOWER_SPAWNED,
    TOWER_DESPAWNED
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
    void Notify(Message msg, int param = 0)
    {
        for (auto* o : observers) {
            o->Update(msg, param);
        }
    }
};