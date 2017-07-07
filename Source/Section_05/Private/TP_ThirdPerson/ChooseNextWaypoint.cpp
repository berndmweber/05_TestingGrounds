// Copyright 2017 Red Rabbit Games, Inc.

#include "ChooseNextWaypoint.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask (UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG (LogTemp, Warning, TEXT ("Executing Task!"));
	return EBTNodeResult::Succeeded;
}
