// Fill out your copyright notice in the Description page of Project Settings.


#include "kdy_2018112051/Public/Bullet.h"

#include "Enemy/Enemy.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

const float ABullet::DefaultMoveSpeed = 800.f;

// Sets default values
ABullet::ABullet() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // BoxComponent
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    SetRootComponent(BoxComponent);
    BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));
    // Bullet resizing
    BoxComponent->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
    BoxComponent->SetCollisionProfileName(TEXT("Bullet"));

    // MeshComponent
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(BoxComponent);

    // Default Variable Setting
    MoveSpeed = DefaultMoveSpeed;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay() {
    Super::BeginPlay();

    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnBulletOverlap);
}

// Called every frame
void ABullet::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    FVector newLoc = GetActorLocation() + GetActorForwardVector() * MoveSpeed * DeltaTime;
    SetActorLocation(newLoc);
}

void ABullet::OnBulletOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                              UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                              const FHitResult& sweepResult) {

    UE_LOG(LogTemp, Display, TEXT("bullet-overlap %s"), *otherActor->GetName());
    AEnemy* enemy = Cast<AEnemy>(otherActor);
    if (enemy) {
        enemy->GetDamage(10);
    }
    Destroy();
}
