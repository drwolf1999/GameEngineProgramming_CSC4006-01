// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <vector>

#include "Wall.h"
#include "GameFramework/Actor.h"
#include "MapGenerator.generated.h"

UCLASS()

class KDY_2018112051_API AMapGenerator : public AActor {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMapGenerator();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    // Called every frame
    void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    int Level = 0;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class AWall> WallFactory;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class AEnemyFactory> EnemyFactoryFactory;

    float TileSize = 100.0f;

private:
    void Generate();

    ///////////////////////////////////
    /// Map Data
    ///////////////////////////////////
    const static std::vector<std::string> _data;
};
