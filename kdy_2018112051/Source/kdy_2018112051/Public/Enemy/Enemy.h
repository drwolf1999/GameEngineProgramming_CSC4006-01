// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class KDY_2018112051_API AEnemy : public AActor {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AEnemy();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    // Called every frame
    void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    class UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* MeshComponent;

    UPROPERTY(EditAnywhere)
    float MoveSpeed = 800.f;
    
    void GetDamage(int damage);
protected:
    int power;

    virtual void MoveTick(float DeltaTime);

    FVector dir;
    
    UFUNCTION()
    void OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                         UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                         const FHitResult& sweepResult);
};
