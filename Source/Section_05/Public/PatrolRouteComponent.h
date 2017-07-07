// Copyright 2017 Red Rabbit Games, Inc.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRouteComponent.generated.h"


/**
* Definition of the patrol route
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION_05_API UPatrolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> GetPatrolPoints ();

protected:
	UPROPERTY (EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;
};
