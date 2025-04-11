// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "EngineUtils.h"
#include "PlayerPawn.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemy::AEnemy() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
	BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));

	BoxComponent->SetCollisionProfileName(TEXT("Enemy"));

	// MeshComponent
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay() {
	Super::BeginPlay();

	int32 drawResult = FMath::RandRange(1, 100);
	if (drawResult <= TraceRate) {
		for (TActorIterator<APlayerPawn> player(GetWorld()); player; ++player) {
			if (player->GetName().Contains(TEXT("BP_PlayerPawn"))) {
				dir = player->GetActorLocation() - GetActorLocation();
				dir.Normalize();
			}
		}
	} else {
		dir = GetActorRightVector();
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	FVector newLoc = GetActorLocation() + dir * MoveSpeed * DeltaTime;
	SetActorLocation(newLoc);
}
