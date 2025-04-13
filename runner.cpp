#include "runner.h"
#include <iostream>

Runner::Runner(string _name, double _time)
    :Athlete(_name),  Time(_time){

}
Runner::Runner(string _name, int _startId, double _time)
    :Athlete(_name, _startId),  Time(_time){

}
double Runner::getTime() const
{
    return Time;
}

void Runner::setTime(double newTime)
{
    Time = newTime;
}

Trainer *Runner::getTrainer() const
{
    return trainer;
}

void Runner::setTrainer(Trainer *newTrainer)
{
    trainer = newTrainer;
}

const void Runner::display()
{
    cout << "StartId: " << Athlete::getStartId() <<  " | Name: " << Athlete::getName() << ", Best time: " << Time  << endl;
}
