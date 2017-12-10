//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Philipp C. Moser on 08.12.17.
//  Copyright © 2017 Philipp C. Moser. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() { Reset(); }

// Getter Methods
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


void FBullCowGame::Reset()
{
    constexpr int MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "ant";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    // Needs to be defined
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString) // TODO get more specific
{
    MyCurrentTry++;
    return false;
}

// receives a VALID guess, increments turn and return 
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment the turn number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    int HiddenWordLength = MyHiddenWord.length();
    
    // loop throught all letters in the guess
    for (int i = 0; i < HiddenWordLength; i++) {
        // compare letters against the hidden word.
        for (int j = 0; j < HiddenWordLength; j++) {
            if(Guess[i] == MyHiddenWord[i]) { // if they match then
                
                if( i == j) { // if they're in the same place
                    BullCowCount.Bulls++; // increment bulls if they're in the same place
                }
                else {
                    BullCowCount.Cows++; // increment cows if they are not.
                }
            }
        }
    }
    
    return BullCowCount;
}

