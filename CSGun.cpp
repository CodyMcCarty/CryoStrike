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

	// Debug shooting from  over shoulder camera
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Owner"));
		return;
	}
	AController* OwnerController = OwnerPawn->GetController();
	if (!OwnerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controller"));
		return;
	}
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	// DrawDebugCamera(GetWorld(), Location, Rotation, 90, 2, FColor::Red, true);
	FVector End = Location + Rotation.Vector() * 10000;
	// DrawDebugPoint(GetWorld(), Location, 20, FColor::Red, true);
	FHitResult HitResult;
	// DrawDebugLine(GetWorld(), Location, End, FColor::Magenta, true);
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(HitResult, Location, End, ECC_GameTraceChannel1);
	UE_LOG(LogTemp, Warning, TEXT("%s"), HitResult.GetActor() ? *HitResult.GetActor()->GetName() : *FString(TEXT("None")));
	if (bSuccess)
	{
		DrawDebugPoint(GetWorld(), HitResult.Location, 20, FColor::Red, true);
	}
}

