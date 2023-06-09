// Fill out your copyright notice in the Description page of Project Settings.


#include "CSShooter.h"

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

}

