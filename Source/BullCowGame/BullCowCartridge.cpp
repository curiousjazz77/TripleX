// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();

    PrintLine(TEXT("The hidden word is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());
    //PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *HiddenWord)); //Debug line

 }

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    //ClearScreen();
    //FString HiddenWord = TEXT("cake"); //TEXT is a macro

    if (bGameOver){
        ClearScreen();
        InitGame();
    } else { //Checking Payer Guess
        ProcessGuess(Input);
}
}

void UBullCowCartridge::InitGame() {

    //Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows!!"));
    HiddenWord = TEXT("cake");
    // Set Lives
    Lives = 5;
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue...."));
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess) {
        if (Guess == HiddenWord){
                PrintLine(TEXT("You have Won!"));
                EndGame();
        } else {
            --Lives;
            PrintLine(TEXT("Lost a life!"));
            if (Lives > 0){
                if (Guess.Len() != HiddenWord.Len()){
                    PrintLine(TEXT("Sorry, try guess again! \n You have %i lives remaining"), Lives);
                }
        } else{
            PrintLine(TEXT("You have no lives left"));
    }
        }

}