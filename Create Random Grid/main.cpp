/* 
Simple program to create a 10x10 grid of random characters.
This will allow the users to easily modify which characters are used and the frequency of each character by expanding upon the SelectEntitiesToAdd() function.
Size of the grid can be modified in line where *charGrid is initilised
*/


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <utility>

void CreateGrid();
std::vector<std::pair<char, int>>* SelectEntitiesToAdd();

int main(){

    srand(time(0));
    CreateGrid();
    
    return 0;
}

void CreateGrid(){

    //Get characters and frequency to add to grid
    std::vector<std::pair<char, int>> *charList = SelectEntitiesToAdd();

    //Initialise grid to a size of 10x10
    std::vector<std::vector<char>> *charGrid = new std::vector<std::vector<char>> (10, std::vector<char>(10));


    //Get the total frequency by adding the frequency of all the characters.
    unsigned int totalRarity = 0;
    //Get the frequencyRange of each character, this is calculated by adding the total frequency of all previous characters inculidng the current chacter frequency to get the frequencyRange for the current character
    std::vector<unsigned int> frequencyRange;
    for (unsigned int i = 0; i < charList->size(); i++){
        totalRarity += charList->at(i).second;
        frequencyRange.push_back(totalRarity);
    }
    
    //Loop through grid
    for (unsigned int i = 0; i < charGrid->size(); i++){
        std::cout << std::endl;
        for (unsigned int j = 0; j < charGrid->size(); j++){
            //Get a random number from 1 to the totalRarity+1
            unsigned int option = 1 + (rand() % totalRarity); 
            //Loop through characters in charList and find the first character where the frequencyRange is less than or equal to the random number
            for (unsigned int l = 0; l < charList->size(); l++){
                //when a character is found, add this to the grid position
                if (option <= frequencyRange.at(l)){
                    charGrid->at(i)[j] = charList->at(l).first;
                    std::cout << " " << charList->at(l).first;
                    break;
                }
            }
        }
    }

    delete charList;
    delete charGrid;

    return;
}

std::vector<std::pair<char, int>>* SelectEntitiesToAdd(){

    //charList will be used to select which character to add to grid position
    std::vector<std::pair<char, int>> *charList = new std::vector<std::pair<char, int>>;

    //Set frequency (higher value, more likely to appear) of character and add to list
    //Add 'T' char to list
    
    charList->push_back(std::make_pair('T', 1));

    //Add 'H' char to list
    
    charList->push_back(std::make_pair('H', 5));

    //Add 'O' char to list
    
    charList->push_back(std::make_pair('O', 3));
    
    //Add 'S' char to list
    
    charList->push_back(std::make_pair('S', 8));

    //Add space char to list

    charList->push_back(std::make_pair(' ', 2));

    return charList;
}