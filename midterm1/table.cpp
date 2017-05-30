#include <iostream>
#include <fstream>
#include <sstream>
#include "table.h"

#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;


void Table::createDeck(string fileName){
    string line;
    ifstream myfile (fileName);
    if (myfile.is_open()){
        theDeck.clear();
        while (! myfile.eof()){
            getline (myfile,line);
            char blank = myfile.peek();
            if (line == "" || line == "\n"){
                // this is to avoid blank lines
            }
            else{
                theDeck.insertHead(line);
                theDeck.insertHead(line);
            }
        }
        std::cout << "file uploaded!\n";
    }
    else{
        myfile.close();
        cout << "Unable to open file"; 
    }
};
void Table::shuffleDeck(){
    srand(40);
    int ranNum = 0;
    if (theDeck.size() > 0){
        for(int i = 0; i < 10; i++){
            ranNum= rand() % theDeck.size() + 1; 
            string temp = theDeck.atpos(ranNum);
            theDeck.removeAt(ranNum);
            theDeck.insertHead(temp);
        }
    }
    else{
        std::cout << "Not enough cards\n";
    }
};
void Table::drawCard(string currentPlayer){
    srand(40);
    int randNum = rand() % theDeck.size() + 1; 
    if(theDeck.size() > 0){
        if(currentPlayer == "me"){
            myHand.insertTail(theDeck.atpos(randNum));
            theDeck.removeAt(randNum);
                for(int j = 1; j <= myHand.size(); j++){
        int k = j+1;
        for( k; k <= myHand.size(); k++){
            if((myHand.atpos(j) == myHand.atpos(k))){
                myHand.removeAt(k);
                myHand.removeAt(j);
                j--;
                myPts++;
                break;
                
                
            }
        }
    }
        }
        else{
            compHand.insertTail(theDeck.atCountBackPos(randNum));
            theDeck.removeCountBack(randNum);
            for(int g = 1; g <= compHand.size(); g++){
        int h = g+1;
        for( h; h <= compHand.size(); h++){
            if((compHand.atpos(g) == compHand.atpos(h))){
                compHand.removeAt(h);
                compHand.removeAt(g);
                g--;
                compPts++;
                break;
                
                
            }
        }
    }
        }
        cout << "Deck after " << displayDeck();
    }
    else{
        std::cout << "Deck is empty\n";
    }
};
void Table::dealCards(int numCards){
    for (int i = 1; i <= numCards; i++){
        srand(40);
        int randNum = rand() % theDeck.size() + 1; 
    
        if(theDeck.size() > 0){
            myHand.insertTail(theDeck.atpos(randNum));
            theDeck.removeAt(randNum);
            compHand.insertTail(theDeck.atCountBackPos(randNum));
            theDeck.removeCountBack(randNum);
        }
    }
    for(int j = 1; j <= myHand.size(); j++){
        int k = j+1;
        for( k; k <= myHand.size(); k++){
            if((myHand.atpos(j) == myHand.atpos(k))){
                myHand.removeAt(k);
                myHand.removeAt(j);
                j--;
                break;
                
                
            }
        }
    }
    for(int g = 1; g <= compHand.size(); g++){
        int h = g+1;
        for( h; h <= compHand.size(); h++){
            if((compHand.atpos(g) == compHand.atpos(h))){
                compHand.removeAt(h);
                compHand.removeAt(g);
                g--;
                break;
                
                
            }
        }
    }
};
void Table::play(int numCards){
    playQuit = 0;
    
    shuffleDeck();//shuffle deck
    dealCards(numCards);//deal deck
    
    string startWinner = "none";
    if (myHand.size() == 0 && compHand.size() != 0){
        startWinner = "me";
    }
    else if (compHand.size() == 0 && myHand.size() != 0){
        startWinner = "comp";
    }
    if(endGame(startWinner) == true){//check for endgame conditions for both comp and use turns
        playQuit = -1;
    }
    for (int i = 0; (playQuit != -1); i++){
        endGame("");
        playMenu();
        
    }
    
};
void Table::playMenu(){
    int playSelect = 0;
    string newCard;

    const int NUM_PLAY_CHOICES = 5;
    std::string playChoices[] ={
        "1. Make Guess",
        "2. Shuffle Deck",
        "3. Display Deck",
        "4. Display Computer Hand",
        "5. Give Up"
    };
    endGame("");
        while (playSelect < NUM_PLAY_CHOICES && playQuit != -1) {
        
        displayPoints(); //show points for both
        std::cout << displayMyHand();//show user deck
        endGame("");
        std::cout << "My turn\n";    
            
        std::cout << endl << "Select a  play option\n";
        for (int i = 0; i < NUM_PLAY_CHOICES; i++) {
            std::cout << playChoices[i] << "\n";
        }
        while(!(cin>>playSelect)) {
            std::cin.clear();
            std::cin.ignore(999,'\n');
            std::cout<<"Invalid data type, Select option\n";
            for (int i = 0; i < NUM_PLAY_CHOICES; i++) {
                    std::cout << playChoices[i] << "\n";
            }
        }
        switch(playSelect){
            case 1:{
                string cardName;
                int cardNum;
                stringstream ss;
                string newString;
                currentPlayer = "me";
                std::cout << "Make a Guess\n";
                while (!checkHand(newString, currentPlayer)){
                    std::cout << "Enter in only the Name of the card\n";
                    while(!(cin>>cardName)) {
                        std::cin.clear();
                        std::cin.ignore(999,'\n');
                        std::cout<<"Invalid data type, enter in a string\n";
                    }
                    ss << cardName << " ";
                    std::cout << "Enter in only the Number of the card\n";
                    while(!(cin>>cardNum)) {
                        std::cin.clear();
                        std::cin.ignore(999,'\n');
                        std::cout<<"Invalid data type, enter in a int\n";
                    }
                    ss << cardNum;
                    newString = ss.str();
                    std::cout << "This is my guess " << newString << endl;
                    if (!checkHand(newString, currentPlayer)){
                        std::cout << "This card is not in your deck, Try again\n";
                        ss.str("");
                        ss.clear();
                    }
                }
                if(checkHand(newString, "comp")){
                    compHand.remove(newString);
                    myHand.remove(newString);
                    std::cout << "Found Match int Computers hand\n";
                    myPts++;
                }
                else{
                    std::cout << "Computer doesnt have card \n";
                    drawCard("me");
                    AIbrain.insertHead(newString);
                }
                endGame("");
                std::cout << "COMPUTER's turn\n";
        
        if (AIbrain.size() > 0 && compHand.findValue(AIbrain.atpos(1))){
            std::cout << "Computer guessed " << newCard << endl;
            newCard = AIbrain.atpos(1);
            AIbrain.removeAt(1);
        }
        else{
            newCard = compHand.atpos(1);
            std::cout << "Computer guessed " << newCard << endl;
        }
        if(checkHand(newCard, "me")){
                compHand.remove(newCard);
                myHand.remove(newCard);
                compPts++;
                std::cout << "You have that card \n";
        }
        else{
            drawCard("comp");
            std::cout << "You do not have that card \n";
        }
                
                
            break;
            }
            case 2:{
                std::cout << "Shuffle the Deck\n";
                shuffleDeck();
            break;
            }
            case 3:{
                std::cout << "Display the Deck\n";
                std::cout << displayDeck();
            break;
            }
            case 4:{
                std::cout << "Display the Computer's Hand\n";
                std::cout << displayCompHand();
            break;
            }
            case 5:{
                std::cout << "Give up \n";
                myHand.clear();
                compHand.clear();
                theDeck.clear();
                AIbrain.clear();
                playQuit = -1;
            break;
            }
            default:{
                std::cout << "Invalid selection, try again \n";
            break;
            }
        }
    }
}
string Table::displayDeck(){
    std::cout << "Deck:";
    return (theDeck.toString());
};
string Table::displayMyHand(){
    std::cout << "My Hand:";
    return (myHand.toString());
};
string Table::displayCompHand(){
    std::cout << "Computer's Hand:";
    return (compHand.toString());
};
int Table::currentDeckSize(){
    return (theDeck.size());
};
bool Table::endGame(string currentPlayer){
    if (myHand.size() == 0 || compHand.size() == 0){
        if (currentPlayer == "me"){
            myPts = myPts + 3;
        }
        else if (currentPlayer == "Both"){
            compPts = compPts + 3;
            myPts = myPts + 3;
        }
        else if (currentPlayer == "comp"){
            compPts = compPts + 3;
        }
        else if(myHand.size() == 0 && compHand.size() != 0){
            myPts = myPts + 3;
        }
        else if(compHand.size() == 0 && myHand.size() != 0){
            compPts = compPts + 3;
        }
        //both == to zero
        else if(myPts == compPts){
            cout << "THERE IS A Tie \n";
        }
        else if (myPts > compPts){
            cout << "YOU WIN with " << myPts << " points!" << endl;
        }
        else {
            cout << "SORRY THE COMPUTER WON " << compPts << " points!" << endl;
        }
        playQuit = -1;
        return true;
    }
};
void Table::displayPoints(){
    std::cout << endl << "GAME POINTS \n";
    std::cout << "My POINTS:      " << myPts << endl;
    std::cout << "Computer POINTS:" << compPts << endl << endl;
};

bool Table::checkHand(string newCard, string currentPlayer){
    if (currentPlayer == "me"){
        if(myHand.findValue(newCard)){
            return true;
        }
    }
    else if (currentPlayer == "comp"){
        if(compHand.findValue(newCard)){
            return true;
        }
    }
};