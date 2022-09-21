#include "CardDeck.h"
#include <vector>


class Blackjack{
    private:
        vector<Card> playercard;
        vector<Card> dealercard;
        int checkcardAS(vector<Card> playercard);
        void printplayercard(vector<Card> playercards);
        int choiceinput(vector<Card> cardplayer);
        int sumvaluecard(vector<Card> cards);
        int convertfromcharvaluetoint(int number);
        bool loose();
        bool win();
        bool endgame(bool win);
        uint16_t checkwincondition(vector<Card> playercard, int sumcardplayer, int sumcarddealer);
    public:
        void startgame();
        ~Blackjack(){
            playercard.clear();
            dealercard.clear();
        }

};

