#include "doctest.h"
#include <stdexcept>
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"


class Test {
    static WarGame::Board fillBoard(){
        WarGame::Board board(10,10);

        board[{0,3}]= new Sniper(1);
        board[{0,2}]= new Sniper(2);
        board[{9,1}]= new FootSoldier(1);
        board[{9,2}]= new FootSoldier(2);
        board[{6,5}]= new ParamedicCommander(1);
        board[{4,0}]= new ParamedicCommander(2);
        board[{2,5}]= new FootCommander(1);
        board[{2,4}]= new FootCommander(2);
        board[{2,1}]= new SniperCommander(1);
        board[{5,3}]= new SniperCommander(2);
        board[{8,4}]= new Paramedic(1);
        board[{8,3}]= new Paramedic(2);

        return board;
    }


    TEST_CASE("Check add Solider") {  //14
        WarGame::Board board = fillBoard();
                CHECK(board.has_soldiers(1));
                CHECK(board.has_soldiers(2));
                CHECK(typeid(board[{9,1}]) == typeid(FootSoldier));
                CHECK(typeid(board[{9,2}]) == typeid(FootSoldier));
                CHECK(typeid(board[{2,5}]) == typeid(FootCommander));
                CHECK(typeid(board[{2,4}]) == typeid(FootCommander));
                CHECK(typeid(board[{0,3}]) == typeid(Sniper));
                CHECK(typeid(board[{0,2}]) == typeid(Sniper));
                CHECK(typeid(board[{2,1}]) == typeid(SniperCommander));
                CHECK(typeid(board[{0,3}]) == typeid(SniperCommander));
                CHECK(typeid(board[{5,1}]) == typeid(Paramedic));
                CHECK(typeid(board[{1,3}]) == typeid(Paramedic));
                CHECK(typeid(board[{4,5}]) == typeid(ParamedicCommander));
                CHECK(typeid(board[{4,0}]) == typeid(ParamedicCommander));
    }

};




