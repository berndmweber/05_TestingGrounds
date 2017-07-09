// Copyright 2017 Red Rabbit Games, Inc.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCCharacter.generated.h"

UCLASS()
class SECTION_05_API ANPCCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY (VisibleDefaultsOnly, Category = "Mesh")
	class USkeletalMeshComponent* NPC_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY (VisibleDefaultsOnly, Category = "Mesh")
	class USceneComponent* NPC_MuzzleLocation;

public:
	// Sets default values for this character's properties
	ANPCCharacter();

	/** Gun muzzle's offset from the characters location */
	UPROPERTY (EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector GunOffset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
