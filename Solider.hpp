#pragma once
#include <math.h>
#include <vector>

using namespace std;


class Solider {

    private:
        int max_health;
        int demage;
        int player_number;
        int current_health;

    public:
    Solider (int max_health, int demage, int player_number, int current_health) :
        max_health(max_health),
        demage(demage),
        player_number(player_number),
        current_health(current_health){}

        virtual ~Solider() {}

        double distance (double x1, double y1, double x2, double y2) {
            return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        }

        virtual void playS (std::vector<std::vector<Solider*>> &board, pair<int,int> location) = 0;

        int get_current_health() {
            return this->current_health;
        }

        int get_max_health() {
            return this->max_health;
        }

        int get_demage() {
            return this->demage;
        }

        void set_demage(int demage) {
            this->demage = demage;
        }

        void set_max_health(int max_health) {
            this->max_health = max_health;
        }

        void set_current_health(int current_health) {
            this->current_health = current_health;
        }

        void set_player_number(int player_number) {
            this->player_number = player_number;
        }

        int get_player_number() {
            return this->player_number;
        }




};

