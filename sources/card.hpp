#ifndef CARD_HPP
#define CARD_HPP

#include <string>
using namespace std;
namespace ariel
{

    enum class Type
    {
        Hearts,
        Diamonds,
        Clubs,
        Spades
    };

    enum class Name
    {
        Two = 2,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace

    };

    class Card
    {
    public:
        Card(Name name, Type type);
        //~Card();

        int getValue();
        Name getName();
        Type getType();
        string getCard();

    private:
        Name _name;
        Type _type;
    };
}

#endif