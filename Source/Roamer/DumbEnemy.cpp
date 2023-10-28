// Fill out your copyright notice in the Description page of Project Settings.


#include "DumbEnemy.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADumbEnemy::ADumbEnemy()
{
	//static UObject* WorldContext = this;

	PrimaryActorTick.bCanEverTick = true;

	DumbRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DumbRoot"));
	RootComponent = DumbRoot;

	DumbMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("DumbMesh"));
	FName socketName = FName(TEXT("rootsock"));
	DumbMesh->SetupAttachment(DumbRoot, socketName);
}

// Called when the game starts or when spawned
void ADumbEnemy::BeginPlay()
{
	Super::BeginPlay();

	PlayerActor = (AActor*)UGameplayStatics::GetPlayerCharacter(this, 0);
	
	if (PlayerActor == nullptr)
	{
		UE_LOG(LogActor, Error, TEXT("************ mPlayerActor is NULL"))
	}
	else
	{
		//UE_LOG(LogActor, Warning, TEXT("************ mPlayerActor is OK"))
		float   dis = this->GetDistanceTo(PlayerActor);
		FVector loc = PlayerActor->GetActorLocation();
		//UE_LOG(LogActor, Warning, TEXT("*************** %f %f %f"), loc.X, loc.Y, loc.Z)
		UE_LOG(LogActor, Warning, TEXT("*************** %s is %f away from me"), *PlayerActor->GetName(), dis)
	}

	mMeshStartPosition = DumbMesh->GetRelativeTransform().GetLocation();
}


void ADumbEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerActor != nullptr)
	{
		
		float   dis = this->GetDistanceTo(PlayerActor);
		FVector meshLocation = mMeshStartPosition;

		if (dis < 250)
			meshLocation.Z += LiftAmount;

		DumbMesh->SetRelativeLocation(meshLocation);
	}
	
}

void ADumbEnemy::LiftCone()
{
	//Mesh->AddImpulse(FVector(0, 0, LiftAmount) * Mesh->GetMass());
	UE_LOG(LogActor, Warning, TEXT("*************** ADumbEnemy::LiftCone() has been called but doing nothing because enabling physics causes conflict"))
}

