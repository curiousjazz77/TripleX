// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();

    PrintLine(TEXT("The hidden word is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());
    //PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *HiddenWord)); //Debug line

    PrintLine(TEXT("Welcome to Bull Cows!!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Press enter to continue...."));
 }

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    //FString HiddenWord = TEXT("cake"); //TEXT is a macro
    if (Input == HiddenWord){
        PrintLine(TEXT("You have Won!"));
    } else {
        if (Input.Len() != HiddenWord.Len()){
            PrintLine(TEXT("The Hidden word is %i characters long, try again!"), HiddenWord.Len());
        }
        PrintLine(TEXT("You have lost! but the # of characters was right"));
    }

}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    // Set Lives
    Lives = 4;
}