// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/Trap.h"

#include "Components/BoxComponent.h"

// Sets default values
ATrap::ATrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// BoxComponent
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
	BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.0f));
	// resizing
	BoxComponent->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	BoxComponent->SetCollisionProfileName(TEXT("Trap"));

	// MeshComponent
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(BoxComponent);
	MeshComponent->SetWorldScale3D(FVector(.1f, 1.f, 1.f));  // 스케일 조정
	MeshComponent->SetRelativeLocation(FVector(50.f, 0, -50.f));
}

// Called when the game starts or when spawned
void ATrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

