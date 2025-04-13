#ifndef RUNNER_H
#define RUNNER_H

#include "athlete.h"
#include "trainer.h"
using namespace std;
#include <string>
class Runner : public Athlete
{
public:
    Runner(string _name, double _time);
    Runner(string _name, int _startId, double _time);
    double getTime() const;
    void setTime(double newTime);

    Trainer *getTrainer() const;
    void setTrainer(Trainer *newTrainer);

    const void display() override;

private:
    double Time;
    Trainer* trainer;
};

#endif // RUNNER_H
