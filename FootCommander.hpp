#pragma once
#include "Soldier.hpp"


using namespace std;


class FootCommander : public Soldier {
public:
    FootCommander (int solider_number) :
            Soldier(150, -20, solider_number,150){}

     void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location) override{}


};



