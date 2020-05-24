#pragma once
#include "Soldier.hpp"
using namespace std;


class Paramedic : public Soldier{
public:
    Paramedic (int solider_number) :
            Soldier(100, 0, solider_number,100){}

    void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location) override{}
};
