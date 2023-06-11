// Fill out your copyright notice in the Description page of Project Settings.


#include "CSPlayerController.h"

#include "Blueprint/UserWidget.h"

void ACSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// TODO: find best practices/coding standard for UE conditional init-statements and != nullptr
	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}

void ACSPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromParent();
	if (bIsWinner)
	{
		if (UUserWidget* WinWidget = CreateWidget(this, WinScreenClass))
		{
			WinWidget->AddToViewport();
		}
	}
	else
	{
		if (UUserWidget* LoseWidget = CreateWidget(this, LoseScreenClass); LoseWidget != nullptr)
		{
			LoseWidget->AddToViewport();
		}
	}
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}


