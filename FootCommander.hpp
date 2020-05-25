#pragma once
#include "Solider.hpp"


using namespace std;


class FootCommander : public Solider {
public:
    FootCommander (int solider_number) :
            Solider(150, -20, solider_number,150){}

     void playS (std::vector<std::vector<Solider*>> &board, pair<int,int> location) override{}

};



