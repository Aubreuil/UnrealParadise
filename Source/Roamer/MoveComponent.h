// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"

// On extreem reached event
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentReachEndPointSignature, bool, IsTopEndpoint); // FNameSignature, paramType, paramName

UCLASS( ClassGroup=(RoamerStuff), meta=(BlueprintSpawnableComponent) )
class ROAMER_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UMoveComponent();

	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove);

	UFUNCTION(BlueprintCallable)
	void ResetMovement();

	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	friend class FMoveComponentVisualizer;

	// Offset to move
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	// Speed
	UPROPERTY(EditAnywhere)
	float	Speed = 1.0f;

	// Enable movement of the component
	UPROPERTY(EditAnywhere)
	bool MoveEnable = true;

	// On extreem reached event
	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndpointReached;

	// Computed locations
	FVector  StartRelativeLocation;
	FVector  MoveOffsetNorm;
	float	 MaxDistance = 0.0f;
	float	 CurDistance = 0.0f;
	int		 MoveDirection = 1;

	
};
