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
FText GetGuess();
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
    constexpr int32 WORD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << WORD_LENGTH;
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
    
    for (int32 count = 1; count <= MaxTries; count++)
    {
        FText Guess = GetGuess(); // TODO make loop checking valid
        
        // submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        // print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

        std::cout << std::endl;
        
        // TODO summarise the game
    }
}

FText GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    
    // get the users input
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    FText Guess = "";
    getline(std::cin, Guess);
    BCGame.CheckGuessValidity(Guess);
    
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
