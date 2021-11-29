#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty)
{
    // Greeting statment, setting up game story.
    std::cout << "\n\nYou're an under paid IT consultant breaking into the level " << Difficulty;
    std::cout << " Udemy server room...\nYou need to enter the correct codes to continue...\n\n"; 
}


bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);

    // Declare three number code.
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum & product to the terminal. 
    std::cout << std::endl; 
    std::cout << "+ There are three numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Player input, guessing code.
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    // Store player guess variables.
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Win/lose condition if/else statement.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Nice, you're in! On to the next one... ***";
        return true;
    }
    else
    {
        std::cout << "\n*** What are you doing?...Try again... ***"; 
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10; // Loop condition(while loop) will check if LevelDifficulty value is lower or equal to MaxDifficulty

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed.
    {
      bool bLevelComplete = PlayGame(LevelDifficulty);  
      std::cin.clear(); // Clears any errors
      std::cin.ignore(); // Discards buffer 

      if (bLevelComplete)
      {
          ++LevelDifficulty;
      }
      
    }
    std::cout << "\n*** So, you completed all 10 levels? You must think you're some real hot shit?! ***\n";
    return 0;   
}   