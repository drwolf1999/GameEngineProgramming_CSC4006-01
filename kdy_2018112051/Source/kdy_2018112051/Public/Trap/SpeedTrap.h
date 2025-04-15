// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>

#include "CoreMinimal.h"
#include "PlayerPawn.h"
#include "Trap.h"
#include "Enemy/Enemy.h"
#include "GameFramework/Actor.h"
#include "SpeedTrap.generated.h"

UCLASS()
class KDY_2018112051_API ASpeedTrap : public ATrap {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpeedTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	                            UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
	                            const FHitResult& sweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
};
