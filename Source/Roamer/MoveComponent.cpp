// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"
#include "Math/Vector.h"

UMoveComponent::UMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMoveComponent::EnableMovement(bool ShouldMove)
{
	MoveEnable = ShouldMove;
	SetComponentTickEnabled(MoveEnable);
}

void UMoveComponent::ResetMovement()
{
	// clear distance and set to origin
	CurDistance = 0.0f;
	SetRelativeLocation(StartRelativeLocation);
	FRotator Rotation = FRotator::ZeroRotator;
	Rotation.Yaw = FMath::RadiansToDegrees(180.0f);
	SetRelativeRotation(Rotation);

	FVector Forward = GetForwardVector();
	UE_LOG(LogActor, Warning, TEXT("Forward vector 180 degrees Yaw X:%f Y:%f Z:%f"), Forward.X, Forward.Y, Forward.Z)
}

void UMoveComponent::SetMoveDirection(int Direction)
{
	MoveDirection = Direction >= 1 ? 1 : -1;
}


void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	StartRelativeLocation = GetRelativeLocation();

	// Compute MaxDistance
	MoveOffsetNorm = MoveOffset;
	MoveOffsetNorm.Normalize();
	MaxDistance = MoveOffset.Length();

	// Rotation
	FRotator Rotation = FRotator::ZeroRotator;
	Rotation.Yaw = FMath::RadiansToDegrees(45.0f);
	SetRelativeRotation(Rotation);

	FVector Forward = GetForwardVector();
	UE_LOG(LogActor, Warning, TEXT("Forward vector 45 degrees Yaw X:%f Y:%f Z:%f"), Forward.X, Forward.Y, Forward.Z)

	// Check if ticking is required
	SetComponentTickEnabled(MoveEnable);
}


void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Set the current distance
	if (MoveEnable)
	{
		CurDistance += DeltaTime * Speed * MoveDirection;

		if (CurDistance >= MaxDistance || CurDistance <= 0.0f)
		{
			MoveDirection *= -1;										// Invert direction

			OnEndpointReached.Broadcast(CurDistance >= MaxDistance);	// Fire event

			CurDistance = FMath::Clamp(CurDistance, 0.0f, MaxDistance); // Clamp distance
		}
	}

	// Compute and set current location
	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * CurDistance);
}

