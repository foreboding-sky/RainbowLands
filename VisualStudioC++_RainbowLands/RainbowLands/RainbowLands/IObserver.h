#pragma once

enum Message;

class IObserver
{
public:
    IObserver() {}
    virtual ~IObserver() {}
    virtual void Update(Message&, int&) = 0;

};