//#include "game.hpp"
#include <iostream>
#include <vector>
#pragma once
#include <stdexcept>
using namespace std;


namespace ariel
{

    class Player
    {
    private:
        string name;

    public:
        //game game;
        Player(string name);
        //~Player();
        
        int stacksize();
        int cardesTaken();
    };
}