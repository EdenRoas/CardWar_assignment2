/**
*test file for the game CARDWAR
*Eden  Roas
*/
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("The first game -> good game")
{
    Player p1("Itamar");
    Player p2("Shaked");
    Game game(p1,p2); 
    //Befor the game was started each player get 26 cards
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    //no one play yet, so no one took cards from the other player
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    //The game start and play random 6 turn
    for (int i=0;i<6;i++) // i == turn --> 2 cards
    {
    CHECK_NOTHROW(game.playTurn());//check if the consructor is ok
    }
    //each player left 20 cards without knowing who won
    CHECK(p1.stacksize() == 20);
    CHECK(p2.stacksize() == 20);
    //together they have 12 cards 
    CHECK(p1.cardesTaken()+ p2.cardesTaken() == 12);
    CHECK(p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken() == 52);

    CHECK_NOTHROW(game.playAll()); //void
    CHECK_NOTHROW(game.printLastTurn());//cant know
    CHECK_NOTHROW(game.printWiner());//cant know who won
    CHECK_NOTHROW(game.printLog());//we cant know the order of the play
    CHECK_NOTHROW(game.printStats());//we cannot know the state of each player

    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);

}

TEST_CASE("The Seconde game -> throw exeption")
{
    Player p3("Stav");
    Player p4("Eden");
    Game game2(p3,p4);
    CHECK_NOTHROW(game2.playAll()); // -> play the game until te end
    //now we want to throw error if we try to play after the game was ended
    for (int i=0;i<6;i++) // i == turn --> 2 cards
    {
    CHECK_THROWS(game2.playTurn());
    }
    CHECK_THROWS(game2.playAll());
    CHECK_THROWS(game2.playTurn());


}

    

    


