// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKillEmAllGameMode.h"

#include "AIController.h"
#include "CSPlayerController.h"
#include "CSShooter.h"
#include "CSShooterAIController.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

void ACSKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		// Must be the player's controller that died
		EndGame(false);
	}

	for (ACSShooterAIController* AIController : TActorRange<ACSShooterAIController>(GetWorld()))
	{
		if (AIController && !AIController->IsDead())
		{
			return;
		}
		EndGame(true); // all AIs are dead
	}
}

void ACSKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
