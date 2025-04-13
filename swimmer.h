#ifndef SWIMMER_H
#define SWIMMER_H

#include "athlete.h"
#include "trainer.h"
#include <string>
class Swimmer : public Athlete
{
public:
    Swimmer(string _name, double _time);
    Swimmer(string _name,int _startId, double _time);
    double getTime() const;
    void setTime(double newTime);

    Trainer *getTrainer() const;
    void setTrainer(Trainer *newTrainer);

    const void display() override;

private:
    double Time;
    Trainer* trainer;
};

#endif // SWIMMER_H
