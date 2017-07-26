#include <iostream>
#include <string>
#include "FBullCowGame.h"
#include "UEStandar.h"

void Introgame();
void PlayGame();
FText Getguess();
bool AskToPlayAguin();

FBullCowGame BCGame;//Intace a new game

int main()
{
	bool bPlayAgin = false;
	do
	{ 
		Introgame();
		PlayGame();
		bPlayAgin=AskToPlayAguin();
	} 
	while (bPlayAgin);
	system("pause");
	return 0;
}
void Introgame()
{
	// Introduce the game
	system("CLS");
	constexpr int32 WORD_LENGTH = 9;
	std::cout << std::endl;
	std::cout << "                             _                               _ \n";
	std::cout << "                            (_)-----------------------------(_)\n";
	std::cout << "                            | |                             | |\n";
	std::cout << "                            | |> Welcome to Bulls and Cows <| |\n";
	std::cout << "                            | |                             | |\n";
	std::cout << "                            |_|-----------------------------|_|\n";
	std::cout << std::endl;
	std::cout << "Can you gess " << WORD_LENGTH;
	std::cout << " leter isogram\n";
}
FText Getguess() 
{
	//Get gess from the player
	std::cout << std::endl;
	int32 CurrnetTry = BCGame.GetCurrentTry();
	std::cout <<"Try "<<CurrnetTry<<". Enterer your Guess:";
	FText Guess = "";
	getline(std::cin, Guess);
	return Guess;
	
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTires();
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = Getguess();
		//submit valid gues to de game, resive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		//print the guess
		std::cout << "Your Guess Was:" << Guess <<std::endl;
		std::cout << std::endl;	
	}
}

bool AskToPlayAguin()
{
	std::cout << "Do you want to paly agion? (y/n)"<<std::endl;
	FText Respoce = "";
	getline(std::cin, Respoce);
	return (Respoce[0] == 'y') || (Respoce[0] == 'Y');
}
