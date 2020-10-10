// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
// #include "Math/UnrealMathUtility.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(Words);
    PrintLine(TEXT("%i"), FMath::RandRange(0, 10));
    InitGame();
 }

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    //ClearScreen();
    //FString HiddenWord = TEXT("cake"); //TEXT is a macro

    if (bGameOver){
        ClearScreen();
        InitGame();
    } else { //Checking Payer Guess
        ProcessGuess(PlayerInput);
}
}

void UBullCowCartridge::InitGame() {

    //Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows!!"));
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    // Set Lives
    Lives = 5;
    bGameOver = false;
    
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue...."));
    //PrintLine(FString::Printf(TEXT("The hidden word is: %s"), *HiddenWord));
    // const TCHAR HW[] = TEXT("cakes");
    // PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
    // PrintLine(TEXT("The 4th character of the Hidden Word is: %c"), HW[3]);
    IsIsogram(HiddenWord);
    
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again!"));

}

void UBullCowCartridge::ProcessGuess(const FString& Guess) {
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
        int32 Bulls, Cows; // another sign we'll have out params; not initialized here
        FBullCowCount Score = GetBullCows(Guess);

        PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);

        //Show the player the bulls and cows
        PrintLine(TEXT("Guess again, you have %i lives left"), Lives);

}

bool UBullCowCartridge::IsIsogram(const FString& Word) const {
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


TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const{

    TArray<FString> ValidWords;

    for (FString Word: WordList){ //range based query

        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word)){
            ValidWords.Emplace(Word); //we add that word to the valid words array
            //PrintLine(TEXT("%s"), *Words[Index]); //remember to dereference
        }
    }
    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const{
    FBullCowCount Count;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++){
        if (Guess[GuessIndex] == HiddenWord[GuessIndex]){
            Count.Bulls ++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++){
            if (Guess[GuessIndex] == HiddenWord[GuessIndex]){
                Count.Cows ++;
                break;
            }
        }
    }
    return Count;
}