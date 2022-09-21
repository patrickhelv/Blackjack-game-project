#include <string>
#include <iostream>
#pragma one;

using namespace std;

enum class Suit{clubs,
                diamonds,
                hearts,
                spades };

enum class Rank{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace };

class Card{
private:
    Suit suit;
    Rank rank;
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    string toString();
    string toStringShort();
};

string suitToString(Suit suit);

string rankToString(Rank rank);

