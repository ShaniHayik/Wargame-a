#pragma once
#include "Soldier.hpp"
using namespace std;


class ParamedicCommander : public Soldier{
public:
    ParamedicCommander (int solider_number) :
            Soldier(200, 0, solider_number,200){}

    void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location) override{}

};


