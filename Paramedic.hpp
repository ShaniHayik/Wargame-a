#pragma once
#include "Solider.hpp"
using namespace std;


class Paramedic : public Solider{
public:
    Paramedic (int solider_number) :
            Solider(100, 0, solider_number,100){}

    void playS (std::vector<std::vector<Solider*>> &board, pair<int,int> location) override{}
};
