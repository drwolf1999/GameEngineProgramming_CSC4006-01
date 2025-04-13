// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/BulletItem.h"

// Sets default values
ABulletItem::ABulletItem() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABulletItem::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ABulletItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ABulletItem::OnPlayerOverlap(APlayerPawn* player) {
	Super::OnPlayerOverlap(player);
}
