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
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}

void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop for the number of turns asking for guesses
    // TODO change from FOR to WHILE loop once we are validating tries
    
    for (int32 count = 1; count <= MaxTries; count++) { // TODO make loop checking valid
        FText Guess = GetValidGuess();
        
        
        // submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        // print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

        std::cout << std::endl;
    
    }
    // TODO summarise the game
}


// loop until the user gives a valid guess
FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do{
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << ". Enter your guess: ";
        FText Guess = "";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
            case EGuessStatus::Not_Isogram:
                std::cout << "Pleaser enter a word without repeating letters.\n"; return "";
                break;
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n"; return "";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n"; return "";
            default:
                return Guess;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK); //keep looping until we get no errors
    
    
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
