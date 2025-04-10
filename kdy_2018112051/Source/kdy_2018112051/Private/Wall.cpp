// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWall::AWall() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// BoxComponent
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
	BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));

	// MeshComponent
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void AWall::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AWall::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
