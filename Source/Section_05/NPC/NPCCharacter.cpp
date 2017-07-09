// Copyright 2017 Red Rabbit Games, Inc.

#include "NPCCharacter.h"
#include "Weapon/Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"


// Sets default values
ANPCCharacter::ANPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPCCharacter::BeginPlay ()
{
	Super::BeginPlay ();

	if (!ensure (GunBlueprint)) { return; }

	auto Mesh = GetMesh ();
	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	Gun = GetWorld ()->SpawnActor<AGun> (GunBlueprint);
	Gun->AttachToComponent (Mesh, FAttachmentTransformRules (EAttachmentRule::SnapToTarget, true), TEXT ("GripPoint"));
	Gun->GunMesh->SetRelativeRotation (FRotator (0.0f, 160.0f, 0.0f));
}
