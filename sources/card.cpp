#include "card.hpp"

using namespace std;
using namespace ariel;

Card::Card(Name name, Type type) : _name(name), _type(type){}
 

int Card::getValue(){
    return (int)_name;
}

Name Card::getName(){
    return _name;
}

Type Card::getType(){
    return _type;
}

string Card::getCard(){
    string res;
    switch (_name)
    {
    case Name::Jack:
        res += "Jack";
        break;
    case Name::Queen:
        res += "Queen";
        break;
    case Name::King:
        res += "King";
        break;        
    case Name::Ace:
        res += "Ace";
        break;      
    default: res += to_string((int)_name);
        break;
    }

    switch (_type)
    {
    case Type::Hearts:
        res += " of Hearts";
        break;
    case Type::Diamonds:
        res += " of Diamonds";
        break;
    case Type::Spades:
        res += " of Spades";
        break;        
    case Type::Clubs:
        res += " of Clubs";
        break;      
    }

    return res;

}