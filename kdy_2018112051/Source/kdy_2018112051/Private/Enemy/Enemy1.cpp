// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy1.h"

// Sets default values
AEnemy1::AEnemy1() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy1::BeginPlay() {
    Super::BeginPlay();

    this->power = 10;
}

// Called every frame
void AEnemy1::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

void AEnemy1::MoveTick(float DeltaTime) {
}
