// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"

#include "CleverPawn.h"

#include "RoamerGameMode.generated.h"

UCLASS(minimalapi)
class ARoamerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARoamerGameMode();

	void InitGameState() override;

private:

	UPROPERTY(EditAnywhere, NoClear)
	//TSubclassOf<ACleverPawn> CustomCleverPawnClass = ACleverPawn::StaticClass(); // limit to ACleverPawn  or sub classes
	TSubclassOf<APawn> CustomCleverPawnClass = ACleverPawn::StaticClass(); // limit to APawn  or sub classes so we include BP_FirstPertson



};



