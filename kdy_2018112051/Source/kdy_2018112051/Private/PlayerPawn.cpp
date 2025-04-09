// Fill out your copyright notice in the Description page of Project Settings.


#include "kdy_2018112051/Public/PlayerPawn.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

const float APlayerPawn::DefaultMoveSpeed = 500.f;

// Sets default values
APlayerPawn::APlayerPawn() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// BoxComponent
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
	BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));

	// MeshComponent
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(BoxComponent);

	FirePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	FirePosition->SetupAttachment(BoxComponent);

	// Default Variable Setting
	MoveSpeed = DefaultMoveSpeed;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	FVector dir = FVector(0, h, v);
	dir.Normalize();
	FVector newLoc = GetActorLocation() + dir * MoveSpeed * DeltaTime;
	SetActorLocation(newLoc);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawn::MoveHorizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawn::MoveVertical);
}

void APlayerPawn::MoveHorizontal(float value) {
	this->h = value;
}

void APlayerPawn::MoveVertical(float value) {
	this->v = value;
}
