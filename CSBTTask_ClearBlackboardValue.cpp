// Fill out your copyright notice in the Description page of Project Settings.


#include "CSBTTask_ClearBlackboardValue.h"

#include "BehaviorTree/BlackboardComponent.h"

UCSBTTask_ClearBlackboardValue::UCSBTTask_ClearBlackboardValue()
{
	NodeName = TEXT("CS Clear BlackBoard Value");
}

EBTNodeResult::Type UCSBTTask_ClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}
