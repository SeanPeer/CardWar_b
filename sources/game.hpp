#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "card.hpp"
#include <vector>
using namespace std;
namespace ariel
{

    class Game
    {
    private:
        Player &_player1, &_player2;
        vector<Card> deck;
        vector<string> game_log;
        int numOfRound;
    public:
        
        Game(Player& player1, Player& player2);
    
        
        void playTurn();
        string printLastTurn();
        void playAll();
        string printWiner();
        void printLog();
        string printStats();

       
       
    };
}
#endif