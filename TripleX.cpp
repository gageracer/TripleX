#include <iostream>
#include <ctime>

void PrintIndroduction(int Difficulty){
    //Welcome message for the player
    std::cout << "\n      Hello, Agent.\n           You have to get the correct password to hack the terminal...\n";
    std::cout << "                You are in Security Level "<< Difficulty << std::endl;
    std::cout << "                 _______________________________________________\n";
    std::cout << "              _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n";
    std::cout << "           _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n";
    std::cout << "        _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n";
    std::cout << "     _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n";
    std::cout << "  _-'.-.-.-.-.-. .---.-. .-----------------------------. .-.---. .---.-.-.-.`-_\n";
    std::cout << " :-----------------------------------------------------------------------------:\n";
    std::cout << " `---._.-----------------------------------------------------------------._.---'\n\n";
}
bool PlayGame(int Difficulty){
    
    PrintIndroduction(Difficulty);
    //Declare 3 number code
    int CodeA = rand()%(4 + Difficulty) + 1;
    int CodeB = rand()%(4 + Difficulty) + 1;
    int CodeC = rand()%(4 + Difficulty) + 1;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product
    std::cout << "+There are 3 numbers in the code\n";
    //std::cout <<CodeA<<CodeB<<CodeC<<std::endl;
    std::cout << "+The codes add-up to: " << CodeSum << "\n";
    std::cout << "+The codes multiply to give: " << CodeProduct << "\n";

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n****Correct Password. Another Security Level detected!****\n";
        return true;
    }
    else
    {
        std::cout << "\n****Incorrect Password.Try Again!!!****\n";
        return false;
    }
}
int main(int argc, char const *argv[])
{   
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = rand() % (5) + 5;

    while (LevelDifficulty <= MaxDifficulty){// Loop the game until all levels defeated

        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "You passed all the security tests. Welcome, Mr.Anderson...\n";
    return 0;
}
