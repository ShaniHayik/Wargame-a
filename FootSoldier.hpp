#pragma once
#include "Solider.hpp"
using namespace std;


class FootSoldier : public Solider {
    public:
    FootSoldier (int solider_number) :
            Solider(100, -10, solider_number,100){}

        void playS (std::vector<std::vector<Solider*>> &board, pair<int,int> location) override{}


};



