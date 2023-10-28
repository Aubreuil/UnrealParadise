// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DumbEnemy.generated.h"

UCLASS()
class ROAMER_API ADumbEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADumbEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Our RootComponent, required so that actor has a transform in the world, UPROPERT() makes it apear in details tab
	UPROPERTY()
	USceneComponent*		DumbRoot;

	// In order to see our Actor in the world, we assign a static mesh object to it, UPROPERTY(EditAnywhere) allows us to change it in details
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent*	DumbMesh;

	
	UFUNCTION(BlueprintCallable)
	void		LiftCone();

	UPROPERTY(EditAnywhere)
	float		LiftAmount;

	AActor* PlayerActor;

private:
	
	
	

	FVector			mMeshStartPosition;

};
