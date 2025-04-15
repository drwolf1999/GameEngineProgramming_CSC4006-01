// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/HideTrap.h"

#include "PlayerPawn.h"

// Sets default values
AHideTrap::AHideTrap() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHideTrap::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AHideTrap::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AHideTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                             int32 OtherBodyIndex) {
	APlayerPawn* player = Cast<APlayerPawn>(OtherActor);
	if (player) {
		UE_LOG(LogTemp, Display, TEXT("HideOFF"));
		player->isHide = false;
	}
}

void AHideTrap::OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                               UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                               const FHitResult& sweepResult) {
	APlayerPawn* player = Cast<APlayerPawn>(otherActor);
	if (player) {
		player->isHide = true;
		UE_LOG(LogTemp, Display, TEXT("HideON"));
	}
}
