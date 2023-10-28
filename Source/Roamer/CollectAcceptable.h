#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CollectAcceptable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI,Blueprintable)
class UCollectAcceptable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ROAMER_API ICollectAcceptable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void CollectThing( UObject* SourceObj, float Count );
};
