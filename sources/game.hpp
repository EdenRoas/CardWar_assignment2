#include <iostream>
#include <vector>
#include <stdexcept>
#include "player.hpp"
//#include "card.hpp"
#pragma once
using namespace std;

namespace ariel
{
    class Game
    {
    
    public:
        
        Game(Player first,Player second);
        //~Game();
        void playTurn();
        string printLastTurn();
        void playAll();
        string printWiner();
        string printLog();
        string printStats();
        
    };

}