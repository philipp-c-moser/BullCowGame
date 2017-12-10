/*
     This is the console executable, that makes use of BullCow class.
     This acts as the view in a MVC pattern, and is responsible for all
     user interaction. For Game logic see the FBullCowGame class.
 */

#include <iostream>
#include "FBullCowGame.hpp"

// Converting to UnrealSyntax
using FText = std::string;
using int32 = int;


// Initialize
void PrintIntro();
FText GetValidGuess();
void PrintGuess(FText GetGuess);
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame;

// Entry Code for Application
int main()
{
    bool bPlayAgain = false;
    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
        // TODO get Game summary
        std::cout << std::endl;
    }
    while(bPlayAgain);
  
    
    return 0; // exit the application
}


// introduce the game
void PrintIntro()
{
    std::cout << "\n\nWelcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame() 
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop asking for guesses while the game is not won
    // and there are still tries remaining
    
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) { 
        FText Guess = GetValidGuess();
    
        
        
        
        // submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
    
    }
    // TODO summarise the game
}


// loop until the user gives a valid guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;

    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        
        // get the users input
        std::cout << "Try " << CurrentTry << ". Enter your guess: ";
        
        std::getline(std::cin, Guess);
        
        // check status and give feedback
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter a uppercase word.\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a isogram.\n";
                break;
            default:
                // assuming the guess is valid
                break;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK); // keep looping until we get no errors
    
    return Guess;
    
}

void PrintGuess(FText GetGuess)
{
    std::cout << "Your guess was: ";
    std::cout << GetGuess;
    std::cout << std::endl;
}


bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)?";
    FText Response = "";
    std::getline(std::cin, Response);
    
    
    return (Response[0] == 'y' || Response[0] == 'Y');
}
