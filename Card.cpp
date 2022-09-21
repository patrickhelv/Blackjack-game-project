#include "Card.h"
#include <map>



using namespace std;

Card::Card(Suit s, Rank r):suit{s},rank{r}{}

Suit Card::getSuit(){
    return suit;
}

Rank Card::getRank(){
    return rank;
}

string suitToString(Suit suit){
    map<Suit, string> suitmap = {
        {Suit::clubs, "clubs"},
        {Suit::diamonds, "diamonds"},
        {Suit::hearts, "hearts"},
        {Suit::spades, "spades"}
    };
    return suitmap[suit];
}

string rankToString(Rank rank){
    map<Rank, string> rankmap = {
        {Rank::two, "two"},
        {Rank::three, "three"},
        {Rank::four, "four"},
        {Rank::five, "five"},
        {Rank::six, "six"},
        {Rank::seven, "seven"},
        {Rank::eight, "eight"},
        {Rank::nine, "nine"},
        {Rank::ten, "ten"},
        {Rank::jack, "jack"},
        {Rank::queen, "queen"},
        {Rank::king, "king"},
        {Rank::ace, "ace"}
    };
    return rankmap[rank];
}

string Card::toString(){
    string out = suitToString(getSuit()) + " " + rankToString(getRank());
    return out;
}

int rankToInt(Rank rank){
    map<Rank, int> rankmapint = {
        {Rank::two, 2},
        {Rank::three, 3},
        {Rank::four, 4},
        {Rank::five, 5},
        {Rank::six, 6},
        {Rank::seven, 7},
        {Rank::eight, 8},
        {Rank::nine, 9},
        {Rank::ten, 10},
        {Rank::jack, 10},
        {Rank::queen, 10},
        {Rank::king, 10},
        {Rank::ace, 1}
    };
    return rankmapint[rank];
}

string Card::toStringShort(){
    string out = suitToString(getSuit())[0] + to_string(rankToInt(getRank()));
    out[0] = toupper(out[0]);
    return out;
}
