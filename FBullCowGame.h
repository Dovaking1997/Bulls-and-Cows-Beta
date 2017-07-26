#pragma once
#include <string>
#include "UEStandar.h"

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame();//constructor
	
	int32 GetMaxTires() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuessValidity(FString);
	//Counts Bulls and Cows
	FBullCowCount SubmitGuess(FString);
private:
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
};