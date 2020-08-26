// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "BullCowGame.h"

// This will start when the game starts
void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
    this->SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s"), *this->m_hiddenWord);

    PrintLine(TEXT("Well come to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), this->m_hiddenWord.Len());
    PrintLine(TEXT("Each wrong answer we will blow one cow!"));

    PrintLine(TEXT("Type you guess and press ENTER"));
}

// This method will trigger every time when player types enter
void UBullCowCartridge::OnInput(const FString& Input)
{
    if (this->m_isGameOver) {
        this->ClearScreen();
        this->SetupGame();
    }else {
        this->ProcessGuess(Input, this->m_lives);
    }
}

void UBullCowCartridge::ProcessGuess(FString Guess, int32 Counter) {
    if(Guess.ToLower() == m_hiddenWord.ToLower()) {
        PrintLine(TEXT("You won the game"));
        this->EndGame();
    } else {
        PrintLine(TEXT("BOOM You are wrong!"));
        auto inputLen = Guess.Len();
        auto hiddenWorld = this->m_hiddenWord.Len();

        if(!this->IsIsogram(Guess)) {
            PrintLine(TEXT("No repeating letters, guess again!"));
            return;
        }

        if(inputLen > hiddenWorld) {
            PrintLine(TEXT("The hidden world has less chars"));
        } else if (inputLen < hiddenWorld) {
            PrintLine(TEXT("The hidden world has more chars"));
        }

        --this->m_lives;

        PrintLine(TEXT("The number of lines you have is %i "), this->m_lives);

        if (this->m_lives <= 0) {
            this->EndGame();
        }
    }
}
bool UBullCowCartridge::IsIsogram(FString word) const {
    for(int32 index = 0, comparison = index + 1; comparison < word.Len(); comparison++) {
        if(word[index] == word[comparison]) {
            UE_LOG(LogTemp, Warning, TEXT("the char is: %s"), &word[index]);
            return false;
        }
    }

    return true;
}

void UBullCowCartridge::SetupGame() {
    this->m_hiddenWord = TEXT("Cow");
    this->m_lives = 4;
    this->m_isGameOver = false;
}

void UBullCowCartridge::EndGame() {
    this->m_isGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}