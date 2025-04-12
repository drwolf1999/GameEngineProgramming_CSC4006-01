// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy2.h"

// Sets default values
AEnemy2::AEnemy2() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy2::BeginPlay() {
    Super::BeginPlay();

    this->power = 20;
}

// Called every frame
void AEnemy2::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

void AEnemy2::MoveTick(float DeltaTime) {
}
