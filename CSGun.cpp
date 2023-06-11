// Fill out your copyright notice in the Description page of Project Settings.


#include "CSGun.h"

#include "Engine/DamageEvents.h"
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
	
	FHitResult Hit;
	FRotator Rotation;
	if (GunTrace(Hit, Rotation))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletImpact, Hit.Location, Rotation.GetInverse());
		if (AActor* HitActor = Hit.GetActor())
		{
			AController* OwnerController = GetOwnerController();
			if (!OwnerController) return;
			FPointDamageEvent DamageEvent(Damage, Hit, -Rotation.Vector(), nullptr);
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}
}

bool ACSGun::GunTrace(FHitResult& Hit, FRotator& Rotation)
{
	AController* OwnerController = GetOwnerController();
	if (!OwnerController) return false;
	
	FVector Location;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	// FVector ShotDirection = -Rotation.Vector()
	// Debug shooting from over shoulder camera.  Left in for future reference
	// DrawDebugCamera(GetWorld(), Location, Rotation, 90, 2, FColor::Red, true);
	FVector End = Location + Rotation.Vector() * 10000;
	// DrawDebugPoint(GetWorld(), Location, 20, FColor::Red, true);
	// DrawDebugLine(GetWorld(), Location, End, FColor::Magenta, true);
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(this);
	CollisionQueryParams.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECC_GameTraceChannel1,
														 CollisionQueryParams);
	// DrawDebugPoint(GetWorld(), Hit.Location, 20, FColor::Red, true);
	// UE_LOG(LogTemp, Warning, TEXT("%s"), Hit.GetActor() ? *Hit.GetActor()->GetName() : *FString(TEXT("None")));
}

AController* ACSGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn) return nullptr;
	return OwnerPawn->GetController();
}
