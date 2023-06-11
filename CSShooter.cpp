// Fill out your copyright notice in the Description page of Project Settings.


#include "CSShooter.h"

#include "CryoStrikeGameModeBase.h"
#include "CSGun.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACSShooter::ACSShooter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACSShooter::BeginPlay()
{
	Super::BeginPlay();

	Gun = GetWorld()->SpawnActor<ACSGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("attach_weapon"));
	Gun->SetOwner(this);

	HP = MaxHP;
}

// Called every frame
void ACSShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACSShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACSShooter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACSShooter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &ACSShooter::Shoot);
}

float ACSShooter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	float TakeDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	TakeDamage = FMath::Min(TakeDamage, HP);
	HP -= TakeDamage;

	if (IsDead())
	{
		if (ACryoStrikeGameModeBase* CSGameMode = GetWorld()->GetAuthGameMode<ACryoStrikeGameModeBase>(); CSGameMode != nullptr)
		{
			CSGameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}
	
	return HP;
}

bool ACSShooter::IsDead() const
{
	return HP < 0.01f;
}

void ACSShooter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ACSShooter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void ACSShooter::Shoot()
{
	Gun->PullTrigger();
}

