#pragma once
#include "Solider.hpp"
using namespace std;


class Sniper : public Solider {
public:
    Sniper (int solider_number) :
            Solider(100, -50, solider_number,100){}

    void playS (std::vector<std::vector<Solider*>> &board, pair<int,int> location) override{}

};


