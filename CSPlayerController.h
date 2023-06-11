// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CSPlayerController.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class CRYOSTRIKE_API ACSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void GameHasEnded(AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float RestartDelay{5.f};

	FTimerHandle RestartTimer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HUDClass;

	UPROPERTY()
	UUserWidget* HUD;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WinScreenClass;
	
};
