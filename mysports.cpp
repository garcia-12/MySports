#include "mysports.h"
#include "runner.h"
#include "swimmer.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cmath>

mySports::mySports() {}

const void mySports::display()
{

    while(true){
        char eingabe;
        string name;
        int license_trainer, athelt_id;
        double time;
        cout << "--- mySports ---" <<endl;
        cout << "(1) Athlet" <<endl;
        cout << "(2) Trainer "<<endl;
        cout << "(3) mySports laden "<<endl;
        cout << "(4) Wettkampf"<<endl;
        cout << "(0) Programm verlassen"<<endl;
        cin >> eingabe;

        switch (eingabe) {
        case '1':{

            char eingabe1;
            cout<< "\n\n\n"<<endl;
            cout << "--- mySports - Athleten ---" <<endl;
            cout << "(a) Athlet anlegen" <<endl;
            cout << "(b) Athlet zuordnen "<<endl;
            cout << "(c) Athlet (einzeln) anzeigen" <<endl;
            cout << "(d) Athleten (alle) anzeigen" <<endl;
            cout << "(e) Athleten loeschen" <<endl;
            cout << "(X) Zurueck zum Hauptmenue"<<endl;
            cin >> eingabe1;

            switch (eingabe1) {
            case 'a':{
                char unterEingabe;
                cout << "--- Athlet anlegen ---" <<endl;
                cout << "1_ Runner"<<endl;
                cout << "2_ Swimmer" <<endl;
                cin >> unterEingabe;
                if(unterEingabe == '1'){
                    cout << "Name :";
                    cin.ignore(10, '\n');
                    getline(cin, name);

                    cout << "Best time :"; cin >> time;

                    Runner* newRunner = new Runner(name, time);
                    list_of_athlete.push_back(newRunner);
                    cout << "Runner "<< newRunner->getName() << " wurde angelegt!"<<endl;
                }
                else if (unterEingabe == '2'){
                    cout << "Name :";
                    cin.ignore(10, '\n');
                    getline(cin, name);

                    cout << "Best time :"; cin >> time;

                    Swimmer* newSwimmer = new Swimmer(name, time);
                    list_of_athlete.push_back(newSwimmer);
                    cout << "Swimmer " << newSwimmer->getName() << " wurde angelegt!"<<endl;

                }
                else{
                    break;
                }
            }

                break;

            case 'b':{

                cout << "Athlet zuordnen" <<endl;
                display_athlete_details();
                cout << "Welcher Athlet willst du zuordnen (mit id) ?"; cin >> athelt_id;
                Athlete* a = FindAthlet_withId(athelt_id);
                if(a == nullptr){
                    cout << "Es gibt keinen Athlet mit diesem Id" <<endl;
                    break;
                }


                display_trainer_details();
                cout << "Licenz des Tariners: "; cin >> license_trainer;
                Trainer* t = FindTrainer_withID(license_trainer);
                if(t == nullptr){
                    cout << "Es gibt keinen   Trainer mit dieser Licenz...!"<<endl;
                    break;
                }else {
                    t->set_an_athlet(a);
                    if(Runner* runner = dynamic_cast<Runner*>(a))
                        runner->setTrainer(t);
                    else if (Swimmer* s = dynamic_cast<Swimmer*>(a))
                        s->setTrainer(t);
                    else
                        cout << "Error with Dynamic_cast... "<<endl;

                    cout << t->getName() << " ist jetzt den Trainer von "<< a->getName() << endl;
                }
            }
            break;
            case 'c':{
                cout << "StartId des Athlets: "; cin >> athelt_id;
                display_an_athlet(athelt_id);
            }
            break;
            case 'd':{
                display_athlete_by_id();
            }
            break;

            case 'e':{
                cout << "---Athlet loscehn"<<endl;
                display_athlete_details();

                cout << "StartId: "; cin >> athelt_id;

                Athlete* at = FindAthlet_withId(athelt_id);
                if(at == nullptr){
                    cout << "kein Athlet mit diesem StartId" <<endl;
                    break;
                }
                for(auto t: list_of_trainer){
                    t->delete_athlet(at);
                }

                auto it = std::find(list_of_athlete.begin(), list_of_athlete.end(), at);
                list_of_athlete.erase(it);
                cout << "Geloescht !" <<endl;


            }
            break;
            case ('x' | 'X'):{
                break;
            }
            default:
                break;
            }
        }
            break;

        case '2':{

            char eingabe2;
            cout << "\n\n"<<endl;
            cout << "--- mySports - Trainer ---" <<endl;
            cout << "(a) Trainer anlegen" <<endl;
            cout << "(b) Trainer zuordnen "<<endl;
            cout << "(c) Trainer (einzeln) anzeigen" <<endl;
            cout << "(d) Trainer (alle) anzeigen" <<endl;
            cout << "(e) Trainer loeschen" <<endl;
            cout << "(f) Athleten trainieren" <<endl;
            cout << "(X) Zurueck zum Hauptmenue"<<endl;
            cin >> eingabe2;

            switch (eingabe2) {
            case 'a':{
                cout << "---Trainer anlegen"<<endl;
                cout << "Name: ";
                cin.ignore(10, '\n');
                getline(cin, name);
                Trainer* newTrainer = new Trainer(name);
                list_of_trainer.push_back(newTrainer);
                cout << "Trainer " << newTrainer->getName() << " wurde angelegt! "<<endl;
            }

            break;
            case 'b':{
                cout << "---Trainer zuordnen"<<endl;
                display_trainer_details();
                cout << "Welcher Trainer willst du zoordnen(mit Licenz): "; cin >> license_trainer;
                Trainer* t = FindTrainer_withID(license_trainer);
                if(t == nullptr){
                    cout << "Es gibt keinen Trainer mit dieser Licenz"<<endl;
                    break;
                }

                display_athlete_details();
                cout << "StartId: "; cin >> athelt_id;
                Athlete* a = FindAthlet_withId(athelt_id);
                if(a == nullptr){
                    cout << "Kein Athlet mit diesem StartId"<<endl;
                    break;
                }

                t->set_an_athlet(a);
                if(Runner* runner = dynamic_cast<Runner*>(a))
                    runner->setTrainer(t);
                else if (Swimmer* s = dynamic_cast<Swimmer*>(a))
                    s->setTrainer(t);
                else
                    cout << "Error with Dynamic_cast... "<<endl;

                cout << t->getName() << " ist jetzt den Trainer von "<< a->getName() << endl;
            }
            break;

            case 'c':{
                cout << "Trainer anzeigen" <<endl;
                cout << "Licenz: "; cin >> license_trainer;
                display_a_trainer(license_trainer);

            }
            break;
            case 'd':{
                cout << "Trainer anzeigen"<<endl;
                display_trainer_all_details();

            }
            break;

            case 'e':{
                cout << "---Trainer loeschen"<<endl;
                display_trainer_details();

                cout << "Lincenz: "; cin >> license_trainer;
                Trainer* t = FindTrainer_withID(license_trainer);
                if(t == nullptr){
                    cout << "Kein Trainer gefunden"<<endl;
                    break;
                }

                for(auto a: list_of_athlete){
                    if(Runner* runner = dynamic_cast<Runner*>(a)){
                        if(runner->getTrainer() == t)
                        {
                            runner->setTrainer(nullptr);
                        }
                    }
                    else if (Swimmer* s = dynamic_cast<Swimmer*>(a))
                    {
                        if(s->getTrainer() == t)
                            s->setTrainer(nullptr);
                    }
                }

                auto it = std::find(list_of_trainer.begin(), list_of_trainer.end(), t);
                list_of_trainer.erase(it);
                cout << "Trainer Geloescht !"<<endl;
            }
            break;
            case 'f':{
                cout << "--- Athleten trainieren" <<endl;
                display_trainer_details();
                cout << "Licenz: " ; cin >> license_trainer;
                athlete_trainieren(license_trainer);
            }
            break;
            case ('x' | 'X'):{
                break;
            }
            default:
                break;
            }
        }
        break;
        case '3':{
            cout << "---mySports laden"<<endl;
            mySportsLaden("mySports.txt");
        }
        break;
        case '4':{
            cout << "---Wettkampf" <<endl;
            cout << "Runner: " <<endl;
            display_runner_byID();

            cout << "\n\n"<<endl;
            cout << "Swimmer: " <<endl;
            display_swimmer_byID();
        }
        break;
        case '0':{
            cout << "Bis Bald... !" <<endl;
            return;
        }
        default:
            break;
        }

    }



}

Trainer *mySports::FindTrainer_withID(const int id)
{
    for (const auto& t: list_of_trainer){
        if(t->getLicense() == id){
            return t;
        }
    }
    return nullptr;
}

Athlete *mySports::FindAthlet_withId(const int id)
{
    for (const auto& t: list_of_athlete){
        if(t->getStartId() == id){
            return t;
        }
    }
    return nullptr;
}

const void mySports::display_trainer_details()
{
    cout << "Name / Licenz" <<endl;
    for (const auto& t: list_of_trainer ){
        cout << t->getName() << " / " << t->getLicense() << endl;
    }
    cout << "\n\n"<<endl;
}

const void mySports::display_athlete_details()
{
    for(const auto& a: list_of_athlete){
        a->display();
    }
    cout << "\n\n"<<endl;
}

const void mySports::display_an_athlet(const int id)
{
    Athlete* a = FindAthlet_withId(id);
    if(a == nullptr)
        cout << "kein Athlet mit diesem StartId"<<endl;
    else{
        a->display();
    }
    cout << "\n\n"<<endl;
}

const void mySports::display_a_trainer(const int id)
{
    Trainer* t = FindTrainer_withID(id);
    if(t == nullptr)
        cout << "kein Athlet mit diesem StartId"<<endl;
    else{
        cout << "Name:" << t->getName() << "; Licenz: " << t->getLicense() <<endl;
        cout << "   ---Athleten: "<<endl;
        for(const auto a: t->getList_of_athlete()){
            a->display();
        }
    }
    cout << "\n\n"<<endl;

}

const void mySports::display_trainer_all_details()
{
    for(const auto t: list_of_trainer ){
        cout << "Name:" << t->getName() << "; Licenz: " << t->getLicense() <<endl;
        cout << "   ---Athleten: "<<endl;
        for(const auto a: t->getList_of_athlete()){
            a->display();
        }
        cout << "\n\n"<<endl;
    }
    cout << "\n\n"<<endl;
}

 void mySports::display_athlete_by_id()
{
    vector <Athlete*> new_list_of_athlete = list_of_athlete;
    std::sort(new_list_of_athlete.begin(), new_list_of_athlete.end(), mySports::parameter_sort);

    cout << "Name / StartID"<<endl;
    for(const auto& a: new_list_of_athlete){
        a->display();
    }
    cout << "\n\n"<<endl;
}

bool mySports::parameter_sort(const Athlete *a1, const Athlete *a2)
{
    return a1->getStartId() < a2->getStartId();
}

void mySports::mySportsLaden(const string &filename)
{

    static bool ist_geladen= false;
    if(ist_geladen){
        cout << "Datei wurde schon mal geladen"<<endl;
        return;
    }

    ifstream file(filename);
    if(!file){
        cout << "Fehler beim Oeffnung !" <<endl;
        return;
    }

    if(file){
        cout << "Ouvert!"<<endl;
    }

    for(Athlete* at: list_of_athlete)
        delete at;
    list_of_athlete.clear();
    cout << "Ath delete"<<endl;

    for(Trainer* t: list_of_trainer)
        delete t;
    list_of_trainer.clear();
    cout << "Trainer delete"<<endl;

    string line, type;
    int checkId_value1 = 1, checkId_value2 = 1;
    while (getline(file, line)) {
        cout << "Lecture..."<<endl;
        if(line.empty())
            continue;
        if(line == "# Runner - 100 m"){
            type = "Runner";
            cout << "Type Runner"<<endl;
            continue;
        }
        else if (line == "# Swimmer - 50 m freestyle"){
            type = "Swimmer";
            cout << "Type Swimmer"<<endl;
            continue;
        }
        else if(line == "# Trainer"){
            type = "Trainer";
            cout << "Type Trainer" <<endl;
            continue;
        }else if(line[0] == '#')
            continue;

        istringstream stream(line);
        if(!line.empty()){
            if(type == "Runner" or type == "Swimmer"){
                string name, id_str, licenz_str, time_str, einheit_str;
                stream >> name >> id_str >> time_str >> einheit_str >> licenz_str;

                try {
                    double time = stod(time_str);
                    int id = stoi(id_str);
                    if(checkId_value1 < id)
                        checkId_value1 = id;

                    if(type == "Runner"){
                        Runner* newRunner = new Runner(name, id, time);
                        list_of_athlete.push_back(newRunner);
                        cout << "New Runner"<<endl;
                    }else if (type == "Swimmer"){
                        Swimmer* newSwimmer = new Swimmer(name, id, time);
                        list_of_athlete.push_back(newSwimmer);
                        cout << "New Trainer" <<endl;
                    }
                } catch (const invalid_argument &e) {
                    cerr << "Error : "<< type << endl;
                    continue;
                }
            } else if(type == "Trainer"){
                string name, licenz_str;
                vector<int> athlete_id_list;

                stream >> name >> licenz_str;

                try {
                    int licenz = stoi(licenz_str);

                    Trainer* newTrainer = new Trainer(name, licenz);
                    list_of_trainer.push_back(newTrainer);
                    cout << "New Trainer"<<endl;

                    int athlet_id;

                    while(stream >> athlet_id){
                        athlete_id_list.push_back(athlet_id);
                        if(checkId_value2 < athlet_id)
                            checkId_value2 = athlet_id;
                    }

                    for(auto atId: athlete_id_list ){
                        Athlete* at = FindAthlet_withId(atId);
                        newTrainer->set_an_athlet(at);
                        cout<<"New Ath zu new Trainer"<<endl;
                    }




                } catch (const invalid_argument &e) {
                    cerr << "Error: " <<endl;
                    continue;
                }
            }
        }

    }
    ist_geladen= true;
    Athlete::setNextId(checkId_value1);
    Trainer::setNextLicense(checkId_value2);
    file.close();
    cout << "Erfolgreich geladen!" <<endl;

}

void mySports::athlete_trainieren(const int id_trainer)
{
    Trainer* t = FindTrainer_withID(id_trainer);
    if(t == nullptr){
        cout << "Kein Trainer..." <<endl;
        return;
    }
    double factor, aktuel_time, r, new_time;

    for(auto at: t->getList_of_athlete()){
        // srand(time(0));
        r = rand()%(5);
        cout << "R= " << r <<endl;
        factor = give_factor_with_srand(r);
        if(Runner* runner = dynamic_cast<Runner*>(at)){
            aktuel_time = runner->getTime();
            new_time = floor((aktuel_time*factor)*100)/100;
            runner->setTime(new_time);
            cout << "New Time: " << runner->getTime() <<endl;

        }else if(Swimmer* swimmer = dynamic_cast<Swimmer*>(at)){
            aktuel_time = swimmer->getTime();
            new_time = floor((aktuel_time*factor)*100)/100;
            swimmer->setTime(new_time);
            cout << "New Time Swimmer: " << swimmer->getTime() <<endl;

        }
    }
}

double mySports::give_factor_with_srand(const int r)
{
    if(r == 0){
        return 3.5;
    }
    else if (r == 1){
        return 0.98;
    }else if (r == 2){
        return 0.99;
    }else if(r == 3){
        return 1;
    }else if(r == 4){
        return 1.01;
    }
    cout <<"Error"<<endl;
    return 0;
}

void mySports::display_runner_byID() const
{
    vector <Runner*> list_of_runner;
    for(auto at: list_of_athlete){
        if(Runner* runner = dynamic_cast<Runner*>(at))
            list_of_runner.push_back(runner);
    }

    std::sort(list_of_runner.begin(), list_of_runner.end(), mySports::parameter_sort_runner);
    for(auto r: list_of_runner)
        r->display();
}

bool mySports::parameter_sort_runner(const Runner *a1, const Runner *a2)
{
    return a1->getTime() < a2->getTime();
}

void mySports::display_swimmer_byID() const
{
    vector <Swimmer*> list_of_swimmer;
    for(auto at: list_of_athlete){
        if(Swimmer* swimmer = dynamic_cast<Swimmer*>(at))
            list_of_swimmer.push_back(swimmer);
    }

    std::sort(list_of_swimmer.begin(), list_of_swimmer.end(), mySports::parameter_sort_swimmer);
    for(auto s: list_of_swimmer)
        s->display();


}

bool mySports::parameter_sort_swimmer(const Swimmer *a1, const Swimmer *a2)
{
    return a1->getTime() < a2->getTime();
}



// void mySports::display_athlete_by_id() {
//     vector<Athlete*> new_list_of_athlete = list_of_athlete;

//     //  Utilisation d'une lambda pour éviter le problème de méthode d'instance
//     std::sort(new_list_of_athlete.begin(), new_list_of_athlete.end(),
//               [](const Athlete* a1, const Athlete* a2) {
//                   return a1->getStartId() > a2->getStartId();
//               });
// }































