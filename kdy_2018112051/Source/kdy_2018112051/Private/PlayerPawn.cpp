// Fill out your copyright notice in the Description page of Project Settings.


#include "kdy_2018112051/Public/PlayerPawn.h"

#include "Bullet.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

const float APlayerPawn::MaxPower = 100.f;
const float APlayerPawn::DefaultMoveSpeed = 500.f;
const float APlayerPawn::RunMoveSpeed = 1000.f;

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

	// ArrowComponent
	FirePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	FirePosition->SetupAttachment(BoxComponent);

	// Default Variable Setting
	power = MaxPower;
	speed = DefaultMoveSpeed;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	MoveTick(DeltaTime);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawn::MoveHorizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawn::MoveVertical);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayerPawn::Run);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayerPawn::Walk);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerPawn::Fire);
}

///////////
/// power
///////////
void APlayerPawn::GainPower(float p) {
	// check available
	power = power + p > APlayerPawn::MaxPower ? APlayerPawn::MaxPower : power + p;
}

void APlayerPawn::LosePower(float p) {
	// check available
	power = power - p < 0 ? 0 : power - p;
}

///////////
/// move
///////////
void APlayerPawn::MoveTick(float DeltaTime) {
	FVector dir = FVector(0, h, v);
	dir.Normalize();
	FVector newLoc = GetActorLocation() + dir * speed * DeltaTime;
	SetActorLocation(newLoc);
}


void APlayerPawn::MoveHorizontal(float value) {
	this->h = value;
}

void APlayerPawn::MoveVertical(float value) {
	this->v = value;
}

void APlayerPawn::Walk() {
	this->speed = DefaultMoveSpeed;
}

void APlayerPawn::Run() {
	this->speed = RunMoveSpeed;
}

void APlayerPawn::Fire() {
	ABullet* bullet = GetWorld()->SpawnActor<ABullet>(BulletFactory, FirePosition->GetComponentLocation(), FirePosition->GetComponentRotation());
}

