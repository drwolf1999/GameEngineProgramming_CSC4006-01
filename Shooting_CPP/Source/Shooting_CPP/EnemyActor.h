// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class SHOOTING_CPP_API AEnemyActor : public AActor {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AEnemyActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    class UBoxComponent *BoxComp;

    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent *MeshComponent;

    UPROPERTY(EditAnywhere)
    int32 TraceRate = 50;

    UPROPERTY(EditAnywhere)
    float MoveSpeed = 800.f;
private:
    FVector dir;
};