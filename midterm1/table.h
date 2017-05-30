#pragma once
#include "list.h"
using namespace std;

class Table {
    public:
    Table(){};
    ~Table(){};
    void createDeck(string fileName);
    void shuffleDeck();
    void drawCard(string currentPlayer);
    void dealCards(int numCards);
    void play(int numCards);
    string displayDeck();
    string displayMyHand();
    string displayCompHand();
    int currentDeckSize();
    bool endGame(string currentPlayer);
    bool checkHand(string newCard,string currentPlayer );
    void displayPoints();
    void playMenu();
    
    
    private:
    int myPts = 0;
    int compPts = 0;
    int playQuit = 0;
    string currentPlayer;
    list <string> theDeck;
    list <string> myHand;
    list <string> compHand;
    list <string> AIbrain;
};