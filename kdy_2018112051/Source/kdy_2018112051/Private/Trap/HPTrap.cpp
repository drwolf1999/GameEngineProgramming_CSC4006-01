// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/HPTrap.h"

#include "PlayerPawn.h"
#include "Enemy/Enemy.h"

// Sets default values
AHPTrap::AHPTrap() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	enemy = std::unordered_map<AEnemy*, float>();
}

// Called when the game starts or when spawned
void AHPTrap::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AHPTrap::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);


	if (player.first) {
		player.second += DeltaTime;
		if (player.second >= 1.f) {
			player.first->GetDamage(5);
			player.second -= 1.f;
		}
	}
	for (std::pair<AEnemy* const, float> e : enemy) {
		e.second += DeltaTime;
		if (e.second >= 1.f) {
			e.second -= 1.f;
			e.first->GetDamage(5);
		}
	}
}

void AHPTrap::OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                             UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                             const FHitResult& sweepResult) {
	APlayerPawn* p = Cast<APlayerPawn>(otherActor);
	if (p) {
		player = std::make_pair(p, 0);
	}

	AEnemy* e = Cast<AEnemy>(otherActor);
	if (e) {
		enemy[e] = 0;
	}
}

void AHPTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex) {
	APlayerPawn* p = Cast<APlayerPawn>(OtherActor);
	if (p) {
		player = std::make_pair(nullptr, 0);
	}

	AEnemy* e = Cast<AEnemy>(OtherActor);
	if (e) {
		enemy.erase(e);
	}
}
