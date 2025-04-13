#include "trainer.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int Trainer::nextLicense = 90000;

Trainer::Trainer(string _name)
    :Name(_name), License(nextLicense){

    nextLicense++;
}

Trainer::Trainer(string _name,int _licenz)
    :Name(_name), License(_licenz){


}

string Trainer::getName() const
{
    return Name;
}

void Trainer::setName(const string &newName)
{
    Name = newName;
}

int Trainer::getLicense() const
{
    return License;
}

vector<Athlete *> Trainer::getList_of_athlete() const
{
    return list_of_athlete;
}

void Trainer::setList_of_athlete(const vector<Athlete *> &newList_of_athlete)
{
    list_of_athlete = newList_of_athlete;
}

void Trainer::set_an_athlet( Athlete *&a)
{
    list_of_athlete.push_back(a);
}

void Trainer::setNextLicense(int newNextLicense)
{
    nextLicense = newNextLicense;
}

void Trainer::delete_athlet(Athlete *at)
{
    auto it = std::find(list_of_athlete.begin(), list_of_athlete.end(), at);
    if(it != list_of_athlete.end())
        list_of_athlete.erase(it);
}



Athlete* Trainer::getID_athlet(const int id) const
{
    for(const auto a: list_of_athlete){
        if(a->getStartId() == id)
            return a;
    }
    return nullptr;
}
