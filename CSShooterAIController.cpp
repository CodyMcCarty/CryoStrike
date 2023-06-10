// Fill out your copyright notice in the Description page of Project Settings.


#include "CSShooterAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"



void ACSShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if(AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	}
}

void ACSShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// if (LineOfSightTo(PlayerPawn))
	// {
	// 	SetFocus(PlayerPawn);
	// 	MoveToActor(PlayerPawn, 200);
	// }
	// else
	// {
	// 	StopMovement();
	// 	ClearFocus(EAIFocusPriority::Gameplay);
	// }
}
