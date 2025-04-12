// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy4.h"

// Sets default values
AEnemy4::AEnemy4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy4::BeginPlay()
{
	Super::BeginPlay();

    this->power = 50;
}

// Called every frame
void AEnemy4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy4::MoveTick(float DeltaTime) {
    AEnemy::MoveTick(DeltaTime);
}

