// Fill out your copyright notice in the Description page of Project Settings.


#include "CSShooterAIController.h"

#include "Kismet/GameplayStatics.h"



void ACSShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SetFocus(PlayerPawn);
}

void ACSShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (LineOfSightTo(PlayerPawn))
	{
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn, 200);
	}
	else
	{
		StopMovement();
		ClearFocus(EAIFocusPriority::Gameplay);
	}
}
