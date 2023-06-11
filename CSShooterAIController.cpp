// Fill out your copyright notice in the Description page of Project Settings.


#include "CSShooterAIController.h"

#include "CSShooter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"



void ACSShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (APawn* ControlledPawn = GetPawn())
	{
		if (UCharacterMovementComponent* MovementComponent = ControlledPawn->FindComponentByClass<UCharacterMovementComponent>())
		{
			MovementComponent->MaxWalkSpeed = 500;
		}
	}

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if(AIBehavior != nullptr && PlayerPawn != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

bool ACSShooterAIController::IsDead() const
{
	ACSShooter* Shooter = Cast<ACSShooter>(GetPawn());
	if (Shooter != nullptr)
	{
		return Shooter->IsDead(); 
	}
	return true;
}

void ACSShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); // Now updated in BTServices
	// if (LineOfSightTo(PlayerPawn))
	// {
	// // 	SetFocus(PlayerPawn);
	// // 	MoveToActor(PlayerPawn, 200);  LastKnownPlayerLocation
	// 	// GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	// 	// GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation()); 
	// }
	// else
	// {
	// // 	StopMovement();
	// // 	ClearFocus(EAIFocusPriority::Gameplay);
	// 	// GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	// }
}
