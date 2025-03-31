// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"

#include "EngineUtils.h"
// #include "PlayerPawn.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemyActor::AEnemyActor() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    FVector boxSize(50, 50, 50);
    BoxComp->SetBoxExtent(boxSize);
    SetRootComponent(BoxComp);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    MeshComponent->SetupAttachment(BoxComp);
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay() {
    Super::BeginPlay();

    int32 r = FMath::RandRange(1, 100);
    if (r <= TraceRate) {
        // for (TActorIterator<APlayerPawn> player(GetWorld()); player; ++player) {
        //     if (player->GetName().Contains(TEXT("BP_PlayerPawn"))) {
        //         dir = player->GetActorLocation() - GetActorLocation();
        //         dir.Normalize();
        //     }
        // }
    } else {
        dir = GetActorForwardVector();
    }
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    FVector newLoc = GetActorLocation() + dir * MoveSpeed * DeltaTime;
    SetActorLocation(newLoc);
}