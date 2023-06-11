// Fill out your copyright notice in the Description page of Project Settings.


#include "CSBTService_PlayerLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UCSBTService_PlayerLocation::UCSBTService_PlayerLocation()
{
	NodeName = TEXT("CS Update Player Location");
}

void UCSBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (Player == nullptr) return;
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());
}
