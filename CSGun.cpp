// Fill out your copyright notice in the Description page of Project Settings.


#include "CSGun.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ACSGun::ACSGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ACSGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACSGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACSGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerP = Cast<APawn>(GetOwner());
	if (!OwnerP)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Owner"));
		return;
	}
	AController* OwnerC = OwnerP->GetController();
	if (!OwnerC)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controller"));
		return;
	}
	FVector L;
	FRotator Rot;
	OwnerC->GetPlayerViewPoint(L, Rot);
	DrawDebugCamera(GetWorld(), L, Rot, 90, 2, FColor::Red, true);
}

