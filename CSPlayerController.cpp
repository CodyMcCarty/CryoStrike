// Fill out your copyright notice in the Description page of Project Settings.


#include "CSPlayerController.h"

#include "Blueprint/UserWidget.h"

void ACSPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if (bIsWinner)
	{
		UUserWidget* WinWidget = CreateWidget(this, WinScreenClass);
		if (WinWidget != nullptr)
		{
			WinWidget->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseWidget = CreateWidget(this, LoseScreenClass);
		if (LoseWidget != nullptr)
		{
			LoseWidget->AddToViewport();
		}
	}
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
