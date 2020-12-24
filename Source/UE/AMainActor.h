#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMainActor.generated.h"

UCLASS()
class UE_API AAMainActor final : public AActor
{
	GENERATED_BODY()
	
public:	
	AAMainActor();

protected:
	virtual void BeginPlay() override;
};
