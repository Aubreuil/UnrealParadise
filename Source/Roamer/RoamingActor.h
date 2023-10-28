#pragma once
// This is a collectable actor not a roaming actor
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "RoamerCharacter.h"
#include "RoamingActor.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJumpTriggerSignature, AActor*, OtherActor, UPrimitiveComponent*, OtherComp); // FNameSignature, paramType, paramName

UCLASS()
class ROAMER_API ARoamingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoamingActor();

	UFUNCTION(BlueprintCallable)
	void			Jump(float speed);

protected:
	virtual void	BeginPlay() override;
	
	UFUNCTION()
	void OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float					ImpulseSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float					Livetime = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UClass*					TriggerClass = ARoamerCharacter::StaticClass();

public:	
	virtual void	Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent*	StaticMesh;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent*			BoxCollider;

	UPROPERTY(BlueprintAssignable)
	FJumpTriggerSignature   OnHitTrigger;

	bool					IsLaunched = false;
};
