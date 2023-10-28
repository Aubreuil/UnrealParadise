#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "CleverPawn.generated.h"

UCLASS()
class ROAMER_API ACleverPawn : public APawn
{
	GENERATED_BODY()

public:
	ACleverPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Mesh being displayed
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent*		PawnMesh;

	// Camera to view the scene
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent*			PawnCamera;

	UPROPERTY(EditAnywhere)
	float			MoveSpeed = 2.0f;
	UPROPERTY(EditAnywhere)
	float			RotationSpeed = 0.66f;

	void			MoveFB(float value);
	void			MoveLR(float value);
	void			Rotate(float value);
};
