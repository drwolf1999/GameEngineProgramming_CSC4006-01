// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/SpeedTrap.h"

// Sets default values
ASpeedTrap::ASpeedTrap() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpeedTrap::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ASpeedTrap::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}


void ASpeedTrap::OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                                UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                                const FHitResult& sweepResult) {
	APlayerPawn* p = Cast<APlayerPawn>(otherActor);
	if (p) {
		p->isBoost = true;
	}

	AEnemy* e = Cast<AEnemy>(otherActor);
	if (e) {
		e->isBoost = true;
	}
}

void ASpeedTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                              int32 OtherBodyIndex) {
	APlayerPawn* p = Cast<APlayerPawn>(OtherActor);
	if (p) {
		p->isBoost = false;
	}

	AEnemy* e = Cast<AEnemy>(OtherActor);
	if (e) {
		e->isBoost = false;
	}
}
