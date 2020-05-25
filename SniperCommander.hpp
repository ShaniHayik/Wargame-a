#pragma once
#include "Solider.hpp"
using namespace std;

class SniperCommander : public Solider {
    public:
    SniperCommander (int solider_number) :
            Solider(120, -100, solider_number,120){}

        void playS (std::vector<std::vector<Solider*>> &board, pair<int,int> location) override{}

};



