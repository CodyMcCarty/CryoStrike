// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CryoStrikeGameModeBase.h"
#include "CSKillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CRYOSTRIKE_API ACSKillEmAllGameMode : public ACryoStrikeGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled) override;

private:
	void EndGame(bool bIsPlayerWinner);
	
};
