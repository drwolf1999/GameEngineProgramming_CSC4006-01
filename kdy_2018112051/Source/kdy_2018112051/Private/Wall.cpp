// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWall::AWall() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // BoxComponent
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    SetRootComponent(BoxComponent);
    BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.0f));
    // resizing
    BoxComponent->SetWorldScale3D(FVector(0.5f, 1.f, 1.f));
    BoxComponent->SetCollisionProfileName(TEXT("Wall"));

    // MeshComponent
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(BoxComponent);
    MeshComponent->SetWorldScale3D(FVector(1.f, 1.f, 1.f));  // 스케일 조정
}

// Called when the game starts or when spawned
void AWall::BeginPlay() {
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Wall ObjectType: %d"), BoxComponent->GetCollisionObjectType());
}

// Called every frame
void AWall::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}
