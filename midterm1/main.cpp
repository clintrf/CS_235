#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include "table.h"
using namespace std;


int main (){
    Table myTable;
    std::string fileName;
    std::string type;
    int typeNum;
    int choiceSelect = 0;
    int selectQuit = 0;
    const int NUM_CHOICES = 4;
    std::string choices[] = {
        "1. Create Deck",
        "2. Display Deck",
        "3. Play",
        "4. Quit"
    };

    while (choiceSelect < NUM_CHOICES || selectQuit != -1) {
       std::cout << "Select a option\n";
        for (int i = 0; i < NUM_CHOICES; i++) {
          std::cout << choices[i] << "\n";
        }
        
        while(!(cin>>choiceSelect)) {
 	        std::cin.clear();
 	        std::cin.ignore(999,'\n');
 	        std::cout<<"Invalid data type, Select option\n";
 	        for (int i = 0; i < NUM_CHOICES; i++) {
                std::cout << choices[i] << "\n";
            }
        }

        switch (choiceSelect) {
            case 1:{
                std::cout << "Create Deck:\n";
                std::cout << "What file will you input?\n";
                std::cin >> fileName;
                myTable.createDeck(fileName);
                break;
            }
            case 2:{
                std::cout << "Displaying Deck\n";
                cout << myTable.displayDeck();
                break;
            }
            case 3:{
                std::cout << "Play\n";
                int numCards = 0;
                if(myTable.currentDeckSize() > 1){
                    std::cout << "There are a total of " << myTable.currentDeckSize() << " cards in the deck\n";
                    std::cout << "How many would you like to start with? (Must be equal or less than ";
                    std::cout << myTable.currentDeckSize()/2 << ")" << endl;
                    while(!(cin>>numCards)) {
                        std::cin.clear();
                        std::cin.ignore(999,'\n');
                        std::cout<<"Invalid data type, How many would you like to start with?\n";
                    }
                    if (numCards <= myTable.currentDeckSize()/2){
                        myTable.play(numCards);
                    }
                    else{
                        std::cout << "Not less than half the deck size\n";
                    }
                    break;
                }
                else{
                    std::cout << "Deck is empty...\n";
                }
            }
            case 4:{
                std::cout << "Quit\n";
                selectQuit = -1;
                break;                
            }
            default:{
                std::cout << "Invalid input, try again or 'Quit' with option 4\n";
                choiceSelect = 0;
                break;
            }
        }
    }
    return 0;
}