#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>
#include "card.hpp"
using namespace std;
namespace ariel
{

    class Player
    {

    public:
        Player();
        Player(std::string);
        
        

        int stacksize();
        int cardesTaken();
        string getName();
        Card removeCard();
        Card addCard(Card card);
        string lastCardPlayed();
        void emptyStack();
        Card addCard_burnt(Card card);


    private:
        std::string _name;
        vector<Card> p_stack;
        vector<Card> cards_won;
        int taken;
        
    };
}
#endif