#pragma once
#include "Soldier.hpp"
using namespace std;


class Sniper : public Soldier {
public:
    Sniper (int solider_number) :
            Soldier(100, -50, solider_number,100){}

    void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location) override{}

};


