// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "CSBTService_PlayerLocationIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class CRYOSTRIKE_API UCSBTService_PlayerLocationIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UCSBTService_PlayerLocationIfSeen();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
