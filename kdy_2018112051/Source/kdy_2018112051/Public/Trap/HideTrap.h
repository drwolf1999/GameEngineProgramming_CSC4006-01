// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trap.h"
#include "GameFramework/Actor.h"
#include "HideTrap.generated.h"

UCLASS()
class KDY_2018112051_API AHideTrap : public ATrap {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHideTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	virtual void OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	                            UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
	                            const FHitResult& sweepResult) override;
};
