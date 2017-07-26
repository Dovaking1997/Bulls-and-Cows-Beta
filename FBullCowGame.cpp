#include "FBullCowGame.h"
#include "UEStandar.h"

FBullCowGame::FBullCowGame(){Reset();}

//Geters
int32 FBullCowGame::GetMaxTires() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

void FBullCowGame::Reset()
{
	MyMaxTries = 5;
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "sol";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//Increment Try #
	MyCurrentTry++;
	//Setup a return variable
	FBullCowCount BullCowCount;
	int32 HiddenWordLegth = MyHiddenWord.length();
	for(int32 MHWchar = 0 ; MHWchar<HiddenWordLegth; MHWchar++)
	{ 
		for(int32 GChar = 0 ; GChar<HiddenWordLegth; GChar++)
		{   
			if(Guess[GChar]==MyHiddenWord[MHWchar])// if they mach
			{  
				if(MHWchar==GChar)// if they are in the same place
				{ 
					BullCowCount.Bulls++;// increment bulls
				}
				else
				{ 
					BullCowCount.Cows++;// increment cows
				}
			}
		}
	}
	return BullCowCount;
}
