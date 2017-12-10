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
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "ant";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
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
    int32 HiddenWordLength = MyHiddenWord.length();
    
    // loop throught all letters in the guess
    for (int32 i = 0; i < HiddenWordLength; i++) {
        // compare letters against the hidden word.
        for (int32 j = 0; j < HiddenWordLength; j++) {
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

