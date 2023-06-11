// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKillEmAllGameMode.h"

#include "CSPlayerController.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

void ACSKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	if (PawnKilled != nullptr)
	{
		APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
		if (PlayerController != nullptr)
		{
			EndGame(false);
		}
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
