#pragma once

enum Message;

class IObserver
{
public:
    IObserver() {}
    virtual ~IObserver() {}
    virtual void Update(Message&) = 0;

};