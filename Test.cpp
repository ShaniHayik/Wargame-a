#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Soldier.hpp"



     WarGame::Board fillBoard(){
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


    TEST_CASE("Add Check") {  //14
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
                CHECK(typeid(board[{5,3}]) == typeid(SniperCommander));
                CHECK(typeid(board[{8,4}]) == typeid(Paramedic));
                CHECK(typeid(board[{8,3}]) == typeid(Paramedic));
                CHECK(typeid(board[{6,5}]) == typeid(ParamedicCommander));
                CHECK(typeid(board[{4,0}]) == typeid(ParamedicCommander));
    }


TEST_CASE("Move Check"){  //17
    WarGame::Board board = fillBoard();
            CHECK(typeid(board[{0,2}])== typeid(Sniper));
            CHECK(typeid(board[{4,0}])== typeid(ParamedicCommander));
            CHECK(board[{0,3}]->get_current_health()==50);
            CHECK(board[{0,2}]->get_current_health()==50);
            CHECK(board[{9,1}]->get_current_health()==90);
            CHECK(board[{9,2}]->get_current_health()==90);
            CHECK(board[{2,4}]->get_current_health()==130);
            CHECK(board[{2,5}]->get_current_health()==130);

            board.move(1,{0,3},WarGame::Board::Down);
            CHECK(board[{0,3}]== nullptr);
            CHECK(typeid(board[{9,2}])==typeid(FootSoldier));
            board.move(1,{9,1},WarGame::Board::Left);
            CHECK(board[{9,1}]==nullptr);
            CHECK(typeid(board[{0,2}])== typeid(Sniper));
            board.move(1,{2,5},WarGame::Board::Down);
            CHECK(board[{2,5}]==nullptr);
            CHECK(typeid(board[{8,4}])== typeid(Paramedic));
            board.move(1,{6,5},WarGame::Board::Up);
            CHECK(board[{6,5}]== nullptr);
            board.move(2,{8,3},WarGame::Board::Up);
            CHECK(board[{8,3}]== nullptr);
            board.move(2,{2,4},WarGame::Board::Up);
            CHECK(board[{2,4}]== nullptr);

}


TEST_CASE("Exceptions") {  //11
    WarGame::Board board = fillBoard();
            CHECK_THROWS(board.move(2, {0,2}, WarGame::Board::Up));
            CHECK_THROWS(board.move(1, {0,3}, WarGame::Board::Up));
            CHECK_THROWS(board.move(2, {4,0}, WarGame::Board::Left));
            CHECK_THROWS(board.move(1, {9,1}, WarGame::Board::Down));
            CHECK_THROWS(board.move(2, {9,2}, WarGame::Board::Down));
            board.move(2,{8,3},WarGame::Board::Down);
            CHECK_THROWS(board.move(2, {9,3}, WarGame::Board::Down));
            board.move(2,{8,4},WarGame::Board::Down);
            CHECK_THROWS(board.move(2, {9,4}, WarGame::Board::Down));
            board.move(1,{2,1},WarGame::Board::Left);
            CHECK_THROWS(board.move(1, {2,0}, WarGame::Board::Left));
            CHECK_THROWS(board.move(1, {2,5}, WarGame::Board::Left));
            CHECK_THROWS(board.move(1, {0,3}, WarGame::Board::Left));
            CHECK_THROWS(board.move(2, {9,2}, WarGame::Board::Left));

}



TEST_CASE("Check Health") {  //13
    WarGame::Board board = fillBoard();
    CHECK(board[{5,3}]->get_max_health()==120);
    CHECK(board[{0,2}]->get_max_health()==100);
    CHECK(board[{4,0}]->get_max_health()==200);
    CHECK(board[{2,1}]->get_max_health()==120);
    CHECK(board[{2,4}]->get_max_health()==150);
    CHECK(board[{2,5}]->get_max_health()==150);
    CHECK(board[{6,5}]->get_max_health()==200);
    CHECK(board[{8,3}]->get_max_health()==100);
    CHECK(board[{8,4}]->get_max_health()==100);
    CHECK(board[{9,2}]->get_max_health()==100);
    CHECK(board[{9,1}]->get_max_health()==100);
    

    board.move(2,{9,2},WarGame::Board::Up);
    CHECK(board[{8,3}]->get_current_health()==100);
    board.move(1,{0,3},WarGame::Board::Down);
    board.move(1,{1,3},WarGame::Board::Down);
    CHECK(board[{2,3}]->get_current_health()==30);
    CHECK(board[{2,4}]->get_current_health()==80);
    board.move(1,{6,5},WarGame::Board::Up);
    board.move(1,{5,5},WarGame::Board::Left);
    CHECK(board[{5,3}]->get_current_health()==120);
}


static WarGame::Board fillBoard2(){
    WarGame::Board board(10,10);

    board[{0,3}]= new Sniper(1);
    board[{0,2}]= new Sniper(2);
    board[{9,1}]= new FootSoldier(1);
    board[{9,2}]= new FootSoldier(2);
    board[{6,1}]= new ParamedicCommander(1);
    board[{0,4}]= new ParamedicCommander(2);
    board[{7,5}]= new FootCommander(1);
    board[{2,4}]= new FootCommander(2);
    board[{2,1}]= new SniperCommander(1);
    board[{6,2}]= new SniperCommander(2);
    board[{8,4}]= new Paramedic(1);
    board[{8,3}]= new Paramedic(2);

    return board;
}


TEST_CASE("Check add Solider 2") {  //15
    WarGame::Board board = fillBoard();
            CHECK(board.has_soldiers(1));
            CHECK(board.has_soldiers(2));
            CHECK(typeid(board[{9,1}]) == typeid(FootSoldier));
            CHECK(typeid(board[{9,2}]) == typeid(FootSoldier));
            CHECK(typeid(board[{2,5}]) == typeid(FootCommander));
            CHECK(typeid(board[{2,4}]) == typeid(FootCommander));
            CHECK(typeid(board[{0,3}]) == typeid(Sniper));
            CHECK(typeid(board[{0,2}]) == typeid(Sniper));
            CHECK(typeid(board[{6,2}]) == typeid(SniperCommander));
            CHECK(typeid(board[{2,1}]) == typeid(SniperCommander));
            CHECK(typeid(board[{8,3}]) == typeid(Paramedic));
            CHECK(typeid(board[{8,4}]) == typeid(Paramedic));
            CHECK(typeid(board[{6,1}]) == typeid(ParamedicCommander));
            CHECK(typeid(board[{0,4}]) == typeid(ParamedicCommander));
}


TEST_CASE("Move function"){  //18
    WarGame::Board board = fillBoard();
    board.move(1,{9,1},WarGame::Board::Down);
            CHECK(board[{9,1}]== nullptr);
            CHECK(typeid(board[{8,1}])==typeid(FootSoldier));
            CHECK(board[{8,1}]->get_max_health()==100);

    board.move(2,{9,2},WarGame::Board::Right);
            CHECK(board[{9,2}]==nullptr);
            CHECK(typeid(board[{9,3}])== typeid(FootSoldier));
            CHECK(board[{9,3}]->get_max_health()==100);

    board.move(1,{2,5},WarGame::Board::Down);
            CHECK(board[{2,5}]==nullptr);
            CHECK(typeid(board[{1,5}])== typeid(FootCommander));
            CHECK(board[{1,5}]->get_max_health()==150);

    board.move(2,{2,4},WarGame::Board::Down);
            CHECK(board[{2,4}]== nullptr);
            CHECK(typeid(board[{1,4}])==typeid(FootCommander));
            CHECK(board[{1,4}]->get_max_health()==150);

    board.move(1,{7,5},WarGame::Board::Up);
            CHECK(board[{7,5}]== nullptr);
            CHECK(typeid(board[{8,5}])==typeid(SniperCommander));
            CHECK(board[{8,5}]->get_max_health()==120);

    board.move(2,{8,3},WarGame::Board::Left);
            CHECK(board[{8,3}]== nullptr);
            CHECK(typeid(board[{8,2}])==typeid(SniperCommander));
            CHECK(board[{8,2}]->get_max_health()==120);
}

TEST_CASE(" Exceptions ") { //11
    WarGame::Board board = fillBoard();
    //Out of range
            CHECK_THROWS(board.move(2, {0, 2}, WarGame::Board::Down));
            CHECK_THROWS(board.move(1, {0, 3}, WarGame::Board::Down));
            CHECK_THROWS(board.move(2, {9, 3}, WarGame::Board::Up));
            CHECK_THROWS(board.move(2, {0, 4}, WarGame::Board::Down));

    //Busy place
            CHECK_THROWS(board.move(2, {0, 4}, WarGame::Board::Left));
            CHECK_THROWS(board.move(1, {0, 3}, WarGame::Board::Right));
            CHECK_THROWS(board.move(2, {0, 2}, WarGame::Board::Right));
            CHECK_THROWS(board.move(1, {6, 1}, WarGame::Board::Right));
            CHECK_THROWS(board.move(2, {6, 2}, WarGame::Board::Left));
            CHECK_THROWS(board.move(1, {8, 5}, WarGame::Board::Left));
            CHECK_THROWS(board.move(1, {8, 4}, WarGame::Board::Right));
            CHECK_THROWS(board.move(1, {8, 4}, WarGame::Board::Right));

}
