// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"

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

    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnEnemyOverlap);
}

// Called every frame
void AEnemy::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

void AEnemy::MoveTick(float DeltaTime) {
}

void AEnemy::GetDamage(int damage) {
    power -= damage;

    if (power <= 0) Destroy();
}

void AEnemy::OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                             UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                             const FHitResult& sweepResult) {
    APlayerPawn* player = Cast<APlayerPawn>(otherActor);
    if (player) {
        player->LosePower(10);
    }
}
