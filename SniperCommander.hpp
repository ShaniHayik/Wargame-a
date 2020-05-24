#include "Soldier.hpp"
using namespace std;

class SniperCommander : public Soldier {
    public:
    SniperCommander (int solider_number) :
            Soldier(120, -100, solider_number,120){}

        void playS (std::vector<std::vector<Soldier*>> &board, pair<int,int> location);

};



