#ifndef TRAINER_H
#define TRAINER_H

#include "athlete.h"
using namespace std;
#include <vector>
#include <string>

class Trainer
{
public:
    Trainer(string _name);
    Trainer(string _name,int _licenz);
    string getName() const;
    void setName(const string &newName);

    int getLicense() const;

    vector<Athlete *> getList_of_athlete() const;
    void setList_of_athlete(const vector<Athlete *> &newList_of_athlete);
    void set_an_athlet( Athlete*& a);

    static void setNextLicense(int newNextLicense);

    void delete_athlet(Athlete* at);
    Athlete *getID_athlet(const int id) const;

private:
    string Name;
    const int License = nextLicense;
    static int nextLicense;
    vector <Athlete*> list_of_athlete;
};

#endif // TRAINER_H
