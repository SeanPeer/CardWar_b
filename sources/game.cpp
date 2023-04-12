#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace ariel;

Game::Game(Player &player1, Player &player2) : _player1(player1), _player2(player2)
{
    this->_player1 = player1;
    this->_player2 = player2;

    numOfRound = 0;

    // Creating all type of cards
    for (int i = 2; i <= 14; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Card card((Name)i, (Type)j);
            // cout << card.getCard() << endl;
            deck.push_back(card);
        }
    }

    // Shuffeling the card deck
    for (unsigned int i = 0; i < 52; i++)
    {
        unsigned int curr_random = (unsigned)rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[curr_random];
        deck[curr_random] = temp;
    }

    // Splitting the card deck to both players
    for (unsigned int i = 0; i < 26; i++)
    {
        player1.addCard(deck[i]);
        player2.addCard(deck[i + 26]);
    }
};

void Game::playTurn()
{
    if (_player1.getName() == _player2.getName())
    {
        throw("a player cannot play with him self !");
    }
    numOfRound++;
    if (_player1.stacksize() > 0 && _player2.stacksize() > 0 && numOfRound <= 26)
    {

        Card card1 = _player1.removeCard();
        Card card2 = _player2.removeCard();

        string turnLog = _player1.getName() + " played " + card1.getCard() + " " + _player2.getName() + " played " + card2.getCard() + ". ";
        // cout << turnLog << endl;

        if (card1.getName() == card2.getName())
        {
            turnLog += "Draw.";
            // cout << turnLog << endl;
            _player1.addCard_burnt(card1);
            _player2.addCard_burnt(card2);
            // cout << _player2.stacksize() << endl;
        }
        else if (card1.getName() > card2.getName())
        {
            turnLog += _player1.getName() + " wins.";
            // cout << turnLog << endl;
            _player1.addCard_burnt(card1);
            _player1.addCard_burnt(card2);
            // cout << _player1.stacksize() << endl;
        }
        else
        {
            turnLog += _player2.getName() + " wins.";
            // cout << turnLog << endl;
            _player2.addCard_burnt(card1);
            _player2.addCard_burnt(card2);
            // cout << _player2.stacksize() << endl;
        }
        game_log.push_back(turnLog);
    }
    // Player cannot play when the game is already finished
    else if (_player1.stacksize() == 0 && _player2.stacksize() == 0)
    {
        throw("cannot play after the game is finished");
    }
    // Cannot pass through 26 rounds
    if (numOfRound == 26)
    {
        if (_player1.stacksize() > _player2.stacksize())
        {
            while (_player2.stacksize() > 0)
            {
                _player1.addCard(_player2.removeCard());
            }
        }
        else
        {
            while (_player1.stacksize() > 0)
            {
                _player2.addCard(_player1.removeCard());
            }
        }

    }
}

string Game::printLastTurn() {
    return game_log.back();
}
void Game::playAll()
{
    while (numOfRound < 26)
    {
        playTurn();
    }
}

string Game::printWiner()
{
    if (_player2.stacksize() == 0)
    {
        return _player1.getName() + "is the winner!\n";
    }
    else
    {
        return _player2.getName() + "is the winner!\n";
    }
}
void Game::printLog() { 
    for(unsigned int i = 0;i < game_log.size();i++) {
        cout << game_log.at(i);
    }
    }
string Game::printStats() { return ""; }
