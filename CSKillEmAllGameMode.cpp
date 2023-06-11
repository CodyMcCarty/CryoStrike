// Fill out your copyright notice in the Description page of Project Settings.


#include "CSKillEmAllGameMode.h"

void ACSKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	if (PawnKilled != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *PawnKilled->GetName());
	}
	
}
