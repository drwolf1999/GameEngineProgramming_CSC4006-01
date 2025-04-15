// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GameFramework/Actor.h"
#include "StopEnemy.generated.h"

UCLASS()

class KDY_2018112051_API AStopEnemy : public AEnemy {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStopEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	const static std::string KEY;

protected:
	virtual void MoveTick(float DeltaTime) override;
	virtual void Die() override;
};
