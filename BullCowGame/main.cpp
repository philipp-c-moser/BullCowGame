#include <iostream>
#include "FBullCowGame.hpp"

void PrintIntro();
std::string GetGuess();
void PrintGuess(std::string GetGuess);
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame;

// Entry Code for Application
int main(int argc, const char * argv[])
{
    do
    {
        PrintIntro();
        PlayGame();
        // TODO get Game summary
        std::cout << std::endl;
    }
    while(AskToPlayAgain());
  
    
    return 0;
}


void PrintIntro()
{
    // introduce the game
    constexpr int WORD_LENGTH = 5;
    std::cout << "Welcome to Bulls and Cows\n";
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}

std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();
    std::string Guess;
    // Get the users input
    std::cout << "Try " << CurrentTry;
    std::cout << ": Please give your guess!\n";
    getline(std::cin, Guess);
    BCGame.CheckGuessValidity(Guess);
    
    return Guess;
    
}

void PrintGuess(std::string GetGuess)
{
    std::cout << "Your guess was: ";
    std::cout << GetGuess;
    std::cout << std::endl;
}

void PlayGame()
{
    int MaxTries = BCGame.GetMaxTries();
    
  
    std::cout << "You have " << MaxTries;
    std::cout << " Guesses" << std::endl;
    for (int count = 1; count <= MaxTries; count++)
    {
        PrintGuess(GetGuess()); // TODO Check for valid guesses
        std::cout << std::endl;
    }
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)?";
    std::string Request = "";
    getline(std::cin, Request);
    
    
    return (Request[0] == 'y' || Request[0] == 'Y');
}
