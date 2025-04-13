#ifndef MYSPORTS_H
#define MYSPORTS_H

#include "athlete.h"
#include "runner.h"
#include "swimmer.h"
#include "trainer.h"
#include <vector>
using namespace std;

class mySports
{
public:
    mySports();
    const void display();
    Trainer* FindTrainer_withID(const int id);
    Athlete* FindAthlet_withId(const int id);
    const void display_trainer_details();
    const void display_athlete_details();
    const void display_an_athlet(const int id);
    const void display_a_trainer(const int id);
    const void display_trainer_all_details();
    void display_athlete_by_id();
    static bool parameter_sort(const Athlete *a1, const Athlete *a2 );

    void mySportsLaden(const string& filename);

    void athlete_trainieren(const int id_trainer);
    double give_factor_with_srand(const int r);

    void display_runner_byID() const;
    static bool parameter_sort_runner(const Runner *a1, const Runner *a2 );
    void display_swimmer_byID() const;
    static bool parameter_sort_swimmer(const Swimmer *a1, const Swimmer *a2 );

private:
    std::vector <Athlete*> list_of_athlete;
    std::vector <Trainer*> list_of_trainer;

};

#endif // MYSPORTS_H
