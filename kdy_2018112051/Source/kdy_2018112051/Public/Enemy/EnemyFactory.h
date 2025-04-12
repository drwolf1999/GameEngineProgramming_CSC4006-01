// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyFactory.generated.h"

UCLASS()

class KDY_2018112051_API AEnemyFactory : public AActor {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AEnemyFactory();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    // Called every frame
    void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    TArray<TSubclassOf<class AEnemy>> Enemy;
};
