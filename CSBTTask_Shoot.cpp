// Fill out your copyright notice in the Description page of Project Settings.


#include "CSBTTask_Shoot.h"

#include "AIController.h"
#include "CSShooter.h"

UCSBTTask_Shoot::UCSBTTask_Shoot()
{
	NodeName = TEXT("CS Shoot");
}

EBTNodeResult::Type UCSBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACSShooter* Shooter = Cast<ACSShooter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Shooter == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	Shooter->Shoot();

	return EBTNodeResult::Succeeded;
}
