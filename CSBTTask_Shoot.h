// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CSBTTask_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class CRYOSTRIKE_API UCSBTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UCSBTTask_Shoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
