// Fill out your copyright notice in the Description page of Project Settings.


#include "CleverPawn.h"

// Sets default values
ACleverPawn::ACleverPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup component hierarchy
	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	RootComponent = PawnMesh;
	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	PawnCamera->SetupAttachment(PawnMesh);
}

// Called when the game starts or when spawned
void ACleverPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACleverPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACleverPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &ACleverPawn::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &ACleverPawn::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &ACleverPawn::Rotate);

}

void ACleverPawn::MoveFB(float value)
{
	auto Location = GetActorLocation();
	Location += value * MoveSpeed * GetActorForwardVector();
	SetActorLocation(Location);
}

void ACleverPawn::MoveLR(float value)
{
	auto Location = GetActorLocation();
	Location += value * MoveSpeed * -GetActorRightVector();
	SetActorLocation(Location);
}

void ACleverPawn::Rotate(float value)
{
	auto Rotation = GetActorRotation();
	Rotation.Yaw += value * RotationSpeed;
	SetActorRotation(Rotation);
}