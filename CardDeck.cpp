#include "CardDeck.h"
#include <ctime>


using namespace std;

CardDeck::CardDeck(){
    for(int j = 0; j < 13; j++){
        for(int i = 0; i < 4; i++){
            Card card{Suit(i), Rank(j)};
            cards.push_back(card);
        }
    }
}

void CardDeck::swap(int index0, int index1){
    Card card = cards[index0];
    cards[index0] = cards[index1];
    cards[index1] = card;

}

void CardDeck::print(){
    for(int i = 0; i < cards.size(); i++){
        cards[i].toString();
    }
}

void CardDeck::printShort(){
    for(int i = 0; i < cards.size(); i++){
        cards[i].toStringShort();   
    }
}

void CardDeck::shuffle(){
    srand(time(nullptr));
    int temp = 0;

    for(int i = 0; i < CardDeck::cards.size(); i++){
        temp = rand() % CardDeck::cards.size();
        swap(i, temp);
    }
}

const Card CardDeck::drawCard(){
    Card card = cards[0];
    cards.erase(cards.begin());
    return card;
}
