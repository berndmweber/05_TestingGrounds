// Copyright 2017 Red Rabbit Games, Inc.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask (UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent ();
	auto Index = BlackboardComp->GetValueAsInt (IndexKey.SelectedKeyName);

	//UE_LOG (LogTemp, Warning, TEXT ("Waypoint Index: %i"), Index);
	return EBTNodeResult::Succeeded;
}
