
#include <iostream>
#include <ctime>

void PrintIntroduction(int Level)
{
    // Welcome messages
    std::cout << "\nYou are a secret agent breaking into a level " << Level << " secure server room level.";
    std::cout << "\n\nEnter the correct code to continue...\n\n";

}

bool PlayGame(int Level)
{
    PrintIntroduction(Level);

    // Declare 3 number code
    int CodaA = rand() % Level + Level;
    int CodeB = rand() % Level + Level;
    int CodeC = rand() % Level + Level;

    int CodeSum = CodaA + CodeB + CodeC;
    int CodeProduct = CodaA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The code numbers add up to: " << CodeSum << std::endl;
    std::cout << "+ The code numbers multiply to: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You cracked the code!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "You set off the alarm!" << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int Level = 1;
    int LevelMax = 10;
    int Lives = 3;

    while (Level <= LevelMax && Lives > 0)
    {
        bool bLevelComplete;
        bLevelComplete = PlayGame(Level);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer
        
        if (bLevelComplete) { ++Level; }
        else { --Lives; }
    }


    if (Lives == 0) { std::cout << "\nYour thieving days are done! Game Over!\n"; }
    else { std::cout << "\nNo lock is safe from you! You win!\n"; }

    return 0;
}
