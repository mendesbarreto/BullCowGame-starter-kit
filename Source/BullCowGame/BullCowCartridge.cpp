// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

// This will start when the game starts
void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
    PrintLine(TEXT("Well come to Bull Cows!"));
    PrintLine(TEXT("Each wrong answer we will blow one cow!"));
}

// This method will trigger every time when player types enter
void UBullCowCartridge::OnInput(const FString& Input)
{
    ClearScreen();

    // Text MACRO will convert all strings in the right encoding
    FString hiddenWord  = TEXT("Cow");


}