// Copyright 2017 Red Rabbit Games, Inc.

#include "PatrollingGuard.h"

void APatrollingGuard::BeginPlay ()
{
	Super::BeginPlay ();

	int32 counter = 0;
	for (auto& PatrolPoint : PatrolPoints) {
		if (ensure (PatrolPoint)) {
			UE_LOG (LogTemp, Warning, TEXT ("%s - PatrolPoint[%i]: %s"), *(GetName ()), counter++, *(PatrolPoint->GetName ()));
		}
	}
}
