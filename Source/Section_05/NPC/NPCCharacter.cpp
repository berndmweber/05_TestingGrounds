// Copyright 2017 Red Rabbit Games, Inc.

#include "NPCCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"


// Sets default values
ANPCCharacter::ANPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	NPC_Gun = CreateDefaultSubobject<USkeletalMeshComponent> (TEXT ("FP_Gun"));
	NPC_Gun->SetOnlyOwnerSee (false);
	NPC_Gun->bCastDynamicShadow = false;
	NPC_Gun->CastShadow = true;
	NPC_Gun->SetupAttachment (RootComponent);

	NPC_MuzzleLocation = CreateDefaultSubobject<USceneComponent> (TEXT ("MuzzleLocation"));
	NPC_MuzzleLocation->SetupAttachment (NPC_Gun);
	NPC_MuzzleLocation->SetRelativeLocation (FVector (0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector (100.0f, 0.0f, 10.0f);
}

// Called when the game starts or when spawned
void ANPCCharacter::BeginPlay ()
{
	Super::BeginPlay ();

	auto Mesh = GetMesh ();
	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	NPC_Gun->AttachToComponent (Mesh, FAttachmentTransformRules (EAttachmentRule::SnapToTarget, true), TEXT ("GripPoint"));
	NPC_Gun->SetRelativeRotation (FRotator (0.0f, 160.0f, 0.0f));
}

// Called every frame
void ANPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
