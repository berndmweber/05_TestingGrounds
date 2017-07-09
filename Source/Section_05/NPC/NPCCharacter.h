// Copyright 2017 Red Rabbit Games, Inc.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCCharacter.generated.h"

UCLASS()
class SECTION_05_API ANPCCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Projectile class to spawn */
	UPROPERTY (EditDefaultsOnly, Category = "Gun")
	TSubclassOf<class AGun> GunBlueprint;

private:
	AGun* Gun;

public:
	// Sets default values for this character's properties
	ANPCCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
