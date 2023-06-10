// Fill out your copyright notice in the Description page of Project Settings.


#include "CSShooterAIController.h"

#include "Kismet/GameplayStatics.h"

void ACSShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	SetFocus(PlayerPawn);
}
