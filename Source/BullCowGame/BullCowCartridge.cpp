// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();

    PrintLine(TEXT("The number of possible words is %i"), Words.Num());
    PrintLine(TEXT("The hidden word is: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());
    //PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *HiddenWord)); //Debug line

    for (int32 Index = 0; Index != 10; Index++){

        if (Words[Index].Len() >= 4 && Words[Index].Len() <= 8){
            PrintLine(TEXT("%s"), *Words[Index]); //remember to dereference
        }
    }
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
    HiddenWord = TEXT("cakes");
    // Set Lives
    Lives = 5;
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue...."));

    // const TCHAR HW[] = TEXT("cakes");
    // PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
    // PrintLine(TEXT("The 4th character of the Hidden Word is: %c"), HW[3]);
    IsIsogram(HiddenWord);
    
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again!"));

}

void UBullCowCartridge::ProcessGuess(FString Guess) {
        if (Guess == HiddenWord){
                PrintLine(TEXT("You have Won!"));
                EndGame();
                return;
        } 
        
        //Check if Isogram
        if (!IsIsogram(Guess)){
            PrintLine(TEXT("There are no repeating letters, guess again!"));
            return;
        }
        //Prompt to guess again
        // check right number of characters
        if (Guess.Len() != HiddenWord.Len()){
            PrintLine(TEXT("The hidden word is %i letter(s) long"), HiddenWord.Len());
            PrintLine(TEXT("Sorry, try guessing again! \n You have %i lives remaining"), Lives);
            return;
        }

        //Remove Life
        PrintLine(TEXT("Lost a life!"));
        --Lives;
        
        if (Lives <= 0){
            ClearScreen();
            PrintLine(TEXT("You have no lives left"));
            PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
            EndGame();
            return;
        }

        //Show the player the bulls and cows
        PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

}

bool UBullCowCartridge::IsIsogram(FString Word) const {
    //For each letter
    // Start at element [0].
    // Compare against the next letter.
    // Until we reach [Word.Len() -1]
    // if any are the same, return false.
    // for (int32 Index = 0; Index < Word.Len(); Index++){
    //     PrintLine(TEXT("%c"), Word[Index]);
    // }
    // int32 Index = 0;
    // int32 Comparison = Index + 1;
    for (int32 Index = 0; Index < Word.Len(); Index++){
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++){
            if (Word[Index] == Word[Comparison]){
                return false;
            }

        }
    }

return true;
}