#include "player.hpp"
#include "card.hpp"
using namespace std;
namespace ariel
{
    Player::Player(){

    };

    Player::Player(string n)
    {
        this->_name = n;
        p_stack = vector<Card>();
    };

    int Player::stacksize()
    {
        return p_stack.size();
    }

    int Player::cardesTaken()
    {
        return cards_won.size();
    }

    // void Player::setCardsTaken(Card num){
    //     for(int i = 0; i < num ; i++){
    //         p_stack.
    //     }
    // }
    string Player::getName()
    {
        return _name;
    }

    Card Player::removeCard()
    {
        if (p_stack.size() < 1)
        {
            throw("no cards in stack");
            
        }

        Card curr = p_stack.back();
        p_stack.pop_back();

        return curr;
    }

    Card Player::addCard(Card card)
    {
        p_stack.push_back(card);
        return card;
    }
    Card Player::addCard_burnt(Card card)
    {
        cards_won.push_back(card);
        return card;
    }
    void Player::emptyStack(){
        p_stack.clear();
    }

}