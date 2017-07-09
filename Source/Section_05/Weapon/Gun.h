// Copyright 2017 Red Rabbit Games, Inc.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"


UCLASS()
class SECTION_05_API AGun : public AActor
{
	GENERATED_BODY()
	
public:
	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY (VisibleDefaultsOnly, Category = "Mesh")
	class USkeletalMeshComponent* GunMesh;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY (VisibleDefaultsOnly, Category = "Mesh")
	class USceneComponent* MuzzleLocation;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class AProjectile> ProjectileClass;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY (EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector GunOffset;

	/** Sound to play each time we fire */
	UPROPERTY (EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class USoundBase* FireSound;

	/** The animation object for the arms mesh */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	class UAnimInstance* AnimInstance;

	/** AnimMontage to play each time we fire */
	UPROPERTY (EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class UAnimMontage* FireAnimation;

	// Sets default values for this actor's properties
	AGun();

	// Called every frame
	virtual void Tick (float DeltaTime) override;

	/** Fires a projectile. */
	void OnFire ();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
