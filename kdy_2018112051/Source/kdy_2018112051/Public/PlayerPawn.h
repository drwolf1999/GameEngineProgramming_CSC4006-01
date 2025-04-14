// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()

class KDY_2018112051_API APlayerPawn : public APawn {
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    APlayerPawn();

protected:
    // Called when the game starts or when spawned
    void BeginPlay() override;

public:
    // Called every frame
    void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

    UPROPERTY(EditAnywhere)
    class UBoxComponent *BoxComponent;

    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent *MeshComponent;

    // bullet
    UPROPERTY(EditAnywhere)
    class UArrowComponent *FirePosition;
    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent *SubMeshComponent;
    UPROPERTY(EditAnywhere)
    TSubclassOf<class ABullet> BulletFactory;

    void Heal(int h);
    void GetDamage(int h);
    void GainPower(int p);
    void LosePower(int p);

    const static int MaxHp;
    const static int MaxPower;
    const static int MaxBullet;
    const static int MaxSkill;

    void EarnBullet(int);

private:
    ///////////
    /// power
    ///////////
    int hp;
    int power;

    ///////////
    /// move
    ///////////
    const static float DefaultMoveSpeed;
    const static float RunMoveSpeed;
    UPROPERTY(EditAnywhere)
    float speed;
    void MoveTick(float h, float v, float DeltaTime);
    void RotationTick(float h, float v, float DeltaTime);
    void Walk();
    void Run();

    float h;
    float v;
    void MoveHorizontal(float h);
    void MoveVertical(float v);

    int bullet;
    void Fire();

    int skill;
    void SKill();
};