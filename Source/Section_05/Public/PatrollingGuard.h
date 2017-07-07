// Copyright 2017 Red Rabbit Games, Inc.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class SECTION_05_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	virtual void BeginPlay () override;
	
protected:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;
};
