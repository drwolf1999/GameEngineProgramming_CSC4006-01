// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Item.h"

#include "Components/BoxComponent.h"

// Sets default values
AItem::AItem() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// BoxComponent
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
	BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));
	// Bullet resizing
	BoxComponent->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	BoxComponent->SetCollisionProfileName(TEXT("Item"));

	// MeshComponent
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(BoxComponent);
	MeshComponent->SetRelativeLocation(FVector(0, 0, -50.f));
}

// Called when the game starts or when spawned
void AItem::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AItem::OnItemOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                          UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                          const FHitResult& sweepResult) {
	OnPlayerOverlap(Cast<APlayerPawn>(otherActor));
}

void AItem::OnPlayerOverlap(APlayerPawn* player) {
	if (!player) {
	}
}
