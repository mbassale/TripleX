#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
    std::cout << std::endl;
    std::cout << "You are a secret agent breaking into a level " << LevelDifficulty << " secure server room..." << std::endl;
    std::cout << "Enter the correct code to continue..." << std::endl;
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // show sum and product
    std::cout << std::endl;
    std::cout << "- There are 3 numbers in the code" << std::endl;
    std::cout << "- The codes add-up to: " << CodeSum << std::endl;
    std::cout << "- The codes multiply to give: " << CodeProduct << std::endl;

    // get player guesses
    int GuessA, GuessB, GuessC;
    std::cout << "> Enter 3 codes: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "*** Well done agent! You have extracted a file! Keep going! ***" << std::endl;
        return true;
    }
    else
    {
        std::cout << "*** You entered the wrong code! Careful agent! Try again! ***" << std::endl;
        return false;
    }
}

int main()
{
    // initialize random seed
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete)
        {
            LevelDifficulty++;
        }
    }
    std::cout << "*** Great work! You got all the files! Now get out of here! ***" << std::endl;
    return 0;
}
