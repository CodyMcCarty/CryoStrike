// Fill out your copyright notice in the Description page of Project Settings.


#include "CSBTService_PlayerLocationIfSeen.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UCSBTService_PlayerLocationIfSeen::UCSBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("CS PlayerLocationIfSeen");
}

void UCSBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
	float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (Player == nullptr) return;
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr) return;
	UBlackboardComponent* BBComponent = OwnerComp.GetBlackboardComponent();
	if (BBComponent == nullptr) return;
	
	if (AIController->LineOfSightTo(Player))
	{
		BBComponent->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
	}
	else
	{
		BBComponent->ClearValue(GetSelectedBlackboardKey());
	}
}
