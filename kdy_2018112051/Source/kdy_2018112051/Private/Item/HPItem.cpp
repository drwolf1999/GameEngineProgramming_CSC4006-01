// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/HPItem.h"

// Sets default values
AHPItem::AHPItem() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHPItem::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AHPItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AHPItem::OnPlayerOverlap(APlayerPawn* player) {
	if (player) {
		player->Heal(50);
		Destroy();
	}
}
