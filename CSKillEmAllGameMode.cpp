// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKillEmAllGameMode.h"

#include "CSPlayerController.h"

void ACSKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	if (PawnKilled != nullptr)
	{
		APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
		if (PlayerController != nullptr)
		{
			PlayerController->GameHasEnded(nullptr, false);
		}
	}
	
}
