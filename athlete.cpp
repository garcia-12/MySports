#include "athlete.h"


int Athlete::nextId = 100000;
Athlete::Athlete(string _name/*, int _startId*/)
    :Name(_name), StartId(nextId) {
    nextId++;
}

Athlete::Athlete(string _name, int _startId)
    :Name(_name), StartId(_startId) {

}

string Athlete::getName() const
{
    return Name;
}

void Athlete::setName(const string &newName)
{
    Name = newName;
}

int Athlete::getStartId() const
{
    return StartId;
}

void Athlete::setNextId(int newNextId)
{
    nextId = newNextId;
}
