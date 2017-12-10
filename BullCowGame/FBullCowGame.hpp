//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Philipp C. Moser on 08.12.17.
//  Copyright © 2017 Philipp C. Moser. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

using FString = std::string;

struct FBullCowCount
{
    int Bulls = 0;
    int Cows = 0;
};

    
#endif /* FBullCowGame_hpp */


class FBullCowGame {
public:
    FBullCowGame(); // constructor
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();
    bool CheckGuessValidity(FString);
    
    // counts bulls & cows and increases try # assuming valid guess
    FBullCowCount SubmitGuess(FString);
    
    
    
    
    
// Please try and ignore this and focus on the interface above
private:
    int MyCurrentTry = 1;
    int MyMaxTries = 5;
    FString MyHiddenWord;
};
