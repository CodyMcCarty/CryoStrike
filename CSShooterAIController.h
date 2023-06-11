// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CSShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class CRYOSTRIKE_API ACSShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

public:
	bool IsDead() const;

private:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;
	
};
