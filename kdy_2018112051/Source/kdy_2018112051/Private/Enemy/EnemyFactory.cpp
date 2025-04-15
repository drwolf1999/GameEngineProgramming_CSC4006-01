// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyFactory.h"

#include "Enemy/Enemy.h"

// Sets default values
AEnemyFactory::AEnemyFactory() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyFactory::BeginPlay() {
	Super::BeginPlay();

	TSubclassOf<AEnemy> e = Enemy[FMath::RandRange(0, Enemy.Num() - 1)];
	GetWorld()->SpawnActor<AEnemy>(e, GetActorLocation(), GetActorRotation());
}

// Called every frame
void AEnemyFactory::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
