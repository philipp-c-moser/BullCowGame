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
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
    // Needs to be defined
    return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const // TODO get more specific
{
    return EWordStatus::OK;
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
    for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
        // compare letters against the hidden word.
        for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
            if(Guess[GChar] == MyHiddenWord[MHWChar]) { // if they match then
                
                if( MHWChar == GChar) { // if they're in the same place
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




