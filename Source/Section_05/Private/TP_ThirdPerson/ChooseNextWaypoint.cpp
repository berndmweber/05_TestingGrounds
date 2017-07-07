// Copyright 2017 Red Rabbit Games, Inc.

#include "ChooseNextWaypoint.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask (UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent ();

	TArray<AActor*> PatrolPoints = GetPatrolPoints (OwnerComp);

	if (PatrolPoints.Num () > 0) {
		int32 Index = SetNextWaypoint (*BlackboardComp, PatrolPoints);
		CycleIndex (*BlackboardComp, PatrolPoints, Index);

		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;
}

TArray<AActor*> UChooseNextWaypoint::GetPatrolPoints (UBehaviorTreeComponent& OwnerComp)
{
	auto PatrollingGuard = Cast<APatrollingGuard> (OwnerComp.GetAIOwner()->GetPawn());

	return PatrollingGuard->GetPatrolPoints ();
}

int32 UChooseNextWaypoint::SetNextWaypoint (UBlackboardComponent& BlackboardComp, TArray<AActor*> PatrolPoints)
{
	auto Index = BlackboardComp.GetValueAsInt (IndexKey.SelectedKeyName);
	BlackboardComp.SetValueAsObject (WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	return Index;
}

void UChooseNextWaypoint::CycleIndex (UBlackboardComponent& BlackboardComp, TArray<AActor*> PatrolPoints, int32 Index)
{
	int32 NewIndex = ++Index % PatrolPoints.Num ();
	BlackboardComp.SetValueAsInt (IndexKey.SelectedKeyName, NewIndex);
}
