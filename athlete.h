#ifndef ATHLETE_H
#define ATHLETE_H

using namespace std;
#include <string>
class Athlete
{
public:
    Athlete(string _name/*, int _startId*/);
    Athlete(string _name, int _startId);
    virtual ~Athlete(){};
    string getName() const;
    void setName(const string &newName);

    int getStartId() const;


    virtual const void display() = 0;
    static void setNextId(int newNextId);

private:
    string Name;
    const int StartId = Athlete::nextId;
    static int nextId;

};

#endif // ATHLETE_H
