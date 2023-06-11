// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSGun.generated.h"

UCLASS()
class CRYOSTRIKE_API ACSGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACSGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();

private:
	bool GunTrace(FHitResult& Hit, FRotator& Rotation);

	AController* GetOwnerController() const;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
	UParticleSystem* BulletImpact;
	
	UPROPERTY(EditAnywhere)
	USoundBase* BulletImpactSfx;

	UPROPERTY(EditAnywhere)
	float Damage{10.f};
};
