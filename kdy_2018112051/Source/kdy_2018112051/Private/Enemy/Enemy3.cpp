// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy3.h"

// Sets default values
AEnemy3::AEnemy3() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
}

// Called when the game starts or when spawned
void AEnemy3::BeginPlay() {
    Super::BeginPlay();
    this->power = 30;
}

// Called every frame
void AEnemy3::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

void AEnemy3::MoveTick(float DeltaTime) {
    AEnemy::MoveTick(DeltaTime);
}
