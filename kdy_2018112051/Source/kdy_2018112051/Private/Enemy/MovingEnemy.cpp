// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/MovingEnemy.h"

#include "UI/UIManager.h"
#include "UI/MainWidget.h"
#include <typeinfo>

const TArray<FVector> AMovingEnemy::DIR = {FVector(0, 1, 0), FVector(0, 0, 1)};

// Sets default values
AMovingEnemy::AMovingEnemy() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingEnemy::BeginPlay() {
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
		UE_LOG(LogTemp, Warning, TEXT("AMovingEnemyTick"));
		if (AUIManager::Instance() && AUIManager::Instance()->IsInitialized()) {
			Create(KEY);
			this->hp = 20;
			this->dir = DIR[FMath::RandRange(0, DIR.Num() - 1)];
			this->dir.Normalize();
			this->flip = 1;
			AUIManager::Instance()->MainUI()->RefreshOrange();
		} else {
			// 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
			GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
		}
	});
}

// Called every frame
void AMovingEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMovingEnemy::MoveTick(float DeltaTime) {
	FVector newLoc = GetActorLocation() + this->MoveSpeed * dir * DeltaTime * flip * (this->isBoost ? 2.f : 1.f);
	FHitResult hit;
	GetWorld()->LineTraceSingleByChannel(hit, GetActorLocation(), newLoc, ECC_GameTraceChannel1);
	if (hit.bBlockingHit) {
		// if (!SetActorLocation(newLoc, true, &hit)) {
		flip *= -1;
	} else {
		SetActorLocation(newLoc);
	}
}

const std::string AMovingEnemy::KEY = "AMovingEnemy";

void AMovingEnemy::Die() {
	Delete(KEY);
	AUIManager::Instance()->MainUI()->RefreshOrange();
	Super::Die();
}

void AMovingEnemy::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                int32 OtherBodyIndex) {
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}

void AMovingEnemy::OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                                  UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                                  const FHitResult& sweepResult) {
	Super::OnEnemyOverlap(overlappedComponent, otherActor, otherComponent, otherBodyIndex, bFromSweep, sweepResult);
}
