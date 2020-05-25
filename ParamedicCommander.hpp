#pragma once
#include "Solider.hpp"
using namespace std;


class ParamedicCommander : public Solider{
public:
    ParamedicCommander (int solider_number) :
            Solider(200, 0, solider_number,200){}

    void playS (std::vector<std::vector<Solider*>> &board, pair<int,int> location) override{}

};


