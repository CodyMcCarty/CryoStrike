// Fill out your copyright notice in the Description page of Project Settings.


#include "CSShooterAIController.h"

#include "Kismet/GameplayStatics.h"

void ACSShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SetFocus(PlayerPawn);
	MoveToActor(PlayerPawn, 200);
}

void ACSShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SetFocus(PlayerPawn);
	MoveToActor(PlayerPawn, 200);
}
