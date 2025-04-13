#include "swimmer.h"
#include <iostream>

Swimmer::Swimmer(string _name, double _time)
    :Athlete(_name), Time(_time){

}

Swimmer::Swimmer(string _name,int _startId, double _time)
    :Athlete(_name, _startId), Time(_time){

}


double Swimmer::getTime() const
{
    return Time;
}

void Swimmer::setTime(double newTime)
{
    Time = newTime;
}

Trainer *Swimmer::getTrainer() const
{
    return trainer;
}

void Swimmer::setTrainer(Trainer *newTrainer)
{
    trainer = newTrainer;
}

const void Swimmer::display()
{
    cout << "StartId: " <<  Athlete::getStartId() << "| Name: " << Athlete::getName() << "; Best time: " << Time  <<endl;
 }
