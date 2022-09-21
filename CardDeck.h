#include <vector>
#include "Card.h"


class CardDeck{
    private:
        vector<Card> cards;
    
    public:
        CardDeck();
        void swap(int index0, int index1);
        void print();
        void printShort();
        void shuffle();
        const Card drawCard();
        ~CardDeck(){
            cards.clear();
        }
};

