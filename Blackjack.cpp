#include "Blackjack.h"

using namespace std;


int Blackjack::checkcardAS(vector<Card> playercard, int asvalue){
    int input = 0;

    for(int i = 0; i < playercard.size(); i++){
        if(playercard[i].getRank() == Rank::ace){
            input++;
        }
    }
    if(input > 0 && asvalue == 0 || (asvalue == 11 || asvalue == 1)){
        if(asvalue == 0 && input == 2){
            for(int i = 0; i < input; i++){
                cout << "Do you want ace to be 1 or 11 ?\n";
                cout << "1) 1" << endl;
                cout << "2) 11" << endl;
                cin >> input;
                while(cin.fail() || input > 2 || input < 1){
                    cin.clear();
                    cin.ignore(std::numeric_limits<int>::max(),'\n');
                    cout << "error you did not enter 1 or 11, re-enter either 1 or 2\n";
                    cout << "Do you want ace to be 1 or 11 ?\n";
                    cout << "1) 1" << endl;
                    cout << "2) 11" << endl;
                    cin >> input;
                }
            }
        }else if(asvalue == 0){

            cout << "Do you want ace to be 1 or 11 ?\n";
            cout << "1) 1" << endl;
            cout << "2) 11" << endl;
            cin >> input;
            while(cin.fail() || input > 2 || input < 1){
                cin.clear();
                cin.ignore(std::numeric_limits<int>::max(),'\n');
                cout << "error you did not enter 1 or 11, re-enter either 1 or 2\n";
                cout << "Do you want ace to be 1 or 11 ?\n";
                cout << "1) 1" << endl;
                cout << "2) 11" << endl;
                cin >> input;
            }
        }
        
        if(input == 1){
            return 1;
        }else{
            return 11;
        }
        
    }
    return 0;
}

int Blackjack::convertfromcharvaluetoint(int number){
    int result = 0;
    vector<int> temp;
    int index = 0;

    for(int i = 48; i < 58; i++){
        temp.push_back(i);
    }
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] == number){
            result = i;
        }
    }
    return result;
    
}

int Blackjack::sumvaluecard(vector<Card> cards){
    string value;
    int sum = 0;
    int temp = 0;
    bool control = false;

    for(int i = 0; i < cards.size(); i++){
        value = cards[i].toStringShort();
        for(int i = 0; i < value.size(); i++){
            if(isdigit(value[i])){ //check if string is a digit 
                temp = static_cast<int>(value[i]); // cast to int but anscii char
                if(temp == 48){ //if ascii 48 = 0 then add 10 and subtract 1 to compensate for the conversion function
                    sum = sum + 10 - 1;
                }
                sum += convertfromcharvaluetoint(temp);
            }
        }
    }
    return sum;
}

void Blackjack::printplayercard(vector<Card> playercard){
    for(int i = 0; i < playercard.size(); i++){
        cout << "Your " << i << " card is " << " : " << playercard[i].toString() << "\n\n";
    }

}

int Blackjack::choiceinput(vector<Card> player){
    int input = 0;

    cout << "What to do now : " << endl;
    cout << "1) draw new card " << endl;
    cout << "2) stand by the cards " << endl;
    cin >> input;

    while(cin.fail() && !(input > 0 && input < 3)){
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cout << "Invalid input you either type in 1 or 2" << endl;
        cout << "What to do now : " << endl;
        cout << "1) draw new card " << endl;
        cout << "2) stand by the cards " << endl;
        cin >> input;
        
    }

    return input;
}

uint16_t Blackjack::checkwincondition(vector<Card> playercard, int sumcardplayer, int sumcarddealer){
    uint16_t finished;
    
    if(sumcardplayer > 21){
        cout << "Your cards have a higher value then 21 " << endl;
        bool temp = endgame(false);
        if(temp){
            finished = 1;
        }else{
            finished = 2;
        }
    }

    if(sumcardplayer == 21 && finished == 0){
        cout << "Your cards is exactly 21 " << endl;
        bool temp = endgame(true);
        if(temp){
            finished = 1;
        }else{
            finished = 2;
        }
    }

    if(sumcarddealer > 21 && finished == 0){
        cout << "the dealer has a value higher then 21 " << endl;
        bool temp = endgame(true);
        if(temp){
            finished = 1;
        }else{
            finished = 2;
        }
    }
    if(finished == 0){
        for(int i = 0; i < playercard.size(); i++){
            if((playercard[i].getRank() == Rank::jack || playercard[i].getRank() == Rank::queen || playercard[i].getRank() == Rank::king)){
                for(int j = 0; j < playercard.size(); j++){
                if(playercard[j].getRank() == Rank::ace){
                        bool temp = endgame(true);
                        if(temp){
                            finished = 1;
                        }else{
                            finished = 2;
                        }
                    }
                }
            }
        }
    }

    return finished;
}

bool Blackjack::endgame(bool win){
    int input = 0;
    bool choice = false;
    
    if(win){
        cout << "you win" << endl;
    }else{
        cout << "you loose" << endl;
    }

    cout << "Want to play again ? : " << endl;
    cout << "1) yes " << endl;
    cout << "2) no" << endl;
    cin >> input;
    while(cin.fail() || input > 2 && input < 1){
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cout << "Invalid input you either type in 1 or 2" << endl;
        cout << "Want to play again ? : " << endl;
        cout << "1) yes " << endl;
        cout << "2) no" << endl;
        cin >> input;
    }
    if(input == 1){
        choice = true;
    }
    playercard.clear();
    dealercard.clear();
    return choice;

}

void Blackjack::startgame(){
    string dot = ".";
    int asvalue = 0;
    bool choice = false;
    int input = 0;
    int sumcardplayer = 0;
    bool ch = false;
    int sumdealer = 0;

    cout << "*** BlackJack ***\n" << "created By @Patrick " << endl;
    cout << "\n\n\n";
    CardDeck carddeck = CardDeck();

    while(!choice){
        ch = false;
        for(int i = 0; i < 6; i++){
            cout << "Starting game shuffling cards " << dot << endl;
            dot += ".";
            carddeck.shuffle();
        }

        for(int i = 0; i < 2; i++){
            cout << "Drawing card for the player and for the dealer " << endl;
            playercard.push_back(carddeck.drawCard());
            dealercard.push_back(carddeck.drawCard());
        }
        while(!ch){
            printplayercard(playercard);
            if(asvalue == 0 || (asvalue == 1 || asvalue == 11)){
                asvalue += checkcardAS(playercard, asvalue);
            }

            if(asvalue == 11){
                sumcardplayer += asvalue + sumvaluecard(playercard) - sumcardplayer - 1;
            }else{
                sumcardplayer += sumvaluecard(playercard) - sumcardplayer;
            }
            cout << "you have in total sum with your cards : " << sumcardplayer << endl;

            

            cout << "The dealer has " << dealercard[0].toString() << endl;
            cout <<"\n\n";
            sumdealer = sumvaluecard(dealercard);
            if(choice == false){
                uint16_t temp = checkwincondition(playercard, sumcardplayer, sumdealer);
                if(temp == 1){
                    ch = true;
                    choice = false;
                }
                if(temp == 2){
                    ch = true;
                    choice = true;
                }
            }
            
            if(ch == false){
                input = choiceinput(playercard);

                if(input == 1){
                    playercard.push_back(carddeck.drawCard());
                    dealercard.push_back(carddeck.drawCard());
                }
                if(input == 2){
                    if(sumdealer < 17){
                        sumdealer = 17;
                    }
                    if(sumcardplayer > sumdealer){
                        choice = !(endgame(true));
                    }else{
                        choice = !(endgame(false));
                    }
                    ch = true;
                }
            }

        }

    }
}

