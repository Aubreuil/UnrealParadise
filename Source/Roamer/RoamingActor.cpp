#include "RoamingActor.h"

ARoamingActor::ARoamingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create the root component
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("StaticMesh") );
	RootComponent = StaticMesh;
	
	// Create the collider box
	BoxCollider = CreateDefaultSubobject<UBoxComponent>( TEXT("BoxCollider") );
	BoxCollider->SetupAttachment(StaticMesh);
}

// Not physics
//void ARoamingActor::Jump(float speed)
//{
//	auto newLocation = GetActorLocation();
//	newLocation.Z += speed;
//	SetActorLocation(newLocation);
//}

// physics
void ARoamingActor::Jump(float speed)
{
	// make sure jump is only executed once
	if (!IsLaunched)
	{
		// execute jump using the physics system
		StaticMesh->AddImpulse(FVector(0.0f, 0.0f, speed * 500.0f));

		// initiate object destruction
		SetActorTickEnabled(true); // SetActorTickInterval(secs)
		IsLaunched = true;
	}
}

void ARoamingActor::BeginPlay()
{
	Super::BeginPlay();

	// Ticking is only required after launching
	SetActorTickEnabled(false);

	// setup per instance OnComponentOverlap event
	FScriptDelegate delegateSubscriber;
	delegateSubscriber.BindUFunction(this, "OnComponentBeginOverlap");
	BoxCollider->OnComponentBeginOverlap.Add(delegateSubscriber);
}

// Called when other actor's component hits collider
// Component		-	our BoxCollider
// OtherActor		-	the Actor that hit our collider
// OtherComp		-	the Component that hit out collider
//
void ARoamingActor::OnComponentBeginOverlap(UBoxComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "EVENT", true, { 3, 3 });

	if ( !IsLaunched && OtherActor->IsA( TriggerClass ) )
	{
		OnHitTrigger.Broadcast(OtherActor, OtherComp);
	}
}

void ARoamingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsLaunched)
	{
		Livetime -= DeltaTime;
		if (Livetime <= 0.f)
			Destroy();
	}
}

