// Copyright Epic Games, Inc. All Rights Reserved.

#include "RoamerGameMode.h"
#include "RoamerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARoamerGameMode::ARoamerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void ARoamerGameMode::InitGameState()
{
	Super::InitGameState();

	// check if no override is active
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
	{
		UE_LOG(LogTemp, Error, TEXT("No override of DefaultPawn"));
		// update to custom implementation
		DefaultPawnClass = CustomCleverPawnClass;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("DefaultPawnClass is overidden"));
	}
}
