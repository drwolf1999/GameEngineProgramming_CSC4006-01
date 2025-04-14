// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GameFramework/Actor.h"
#include "MovingEnemy.generated.h"

UCLASS()
class KDY_2018112051_API AMovingEnemy : public AEnemy {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMovingEnemy();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    // Called every frame
    void Tick(float DeltaTime) override;
    const static std::string KEY;

protected:
    void MoveTick(float DeltaTime) override;
	virtual void Die() override;
};
