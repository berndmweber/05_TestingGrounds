// Copyright 2017 Red Rabbit Games, Inc.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * AI Code to choose next waypoint to go to
 */
UCLASS()
class SECTION_05_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	/** starts this task, should return Succeeded, Failed or InProgress
	*  (use FinishLatentTask() when returning InProgress)
	* this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual EBTNodeResult::Type ExecuteTask (UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY (EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector IndexKey;

	UPROPERTY (EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WaypointKey;

private:
	TArray<AActor*> GetPatrolPoints (UBehaviorTreeComponent& OwnerComp);
	int32 SetNextWaypoint (UBlackboardComponent& BlackboardComp, TArray<AActor*> PatrolPoints);
	void CycleIndex (UBlackboardComponent& BlackboardComp, TArray<AActor*> PatrolPoints, int32 Index);
};
