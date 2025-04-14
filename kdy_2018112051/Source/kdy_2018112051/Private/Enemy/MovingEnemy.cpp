// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/MovingEnemy.h"

#include "KDYGameModeBase.h"
#include "UI/MainWidget.h"
#include <typeinfo>

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
		if (AKDYGameModeBase::instance && AKDYGameModeBase::instance->IsInitialized) {
			AEnemy::Create(AMovingEnemy::KEY);
		    UE_LOG(LogTemp, Warning, TEXT("AMovingEnemySpawned %d"), GetTotalCount(AMovingEnemy::KEY));
		
this->power = 20;
			AKDYGameModeBase::instance->MainUI()->RefreshOrange();
		}/* else {
			// 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
			GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
		}*/
	});
}

// Called every frame
void AMovingEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMovingEnemy::MoveTick(float DeltaTime) {
}

const std::string AMovingEnemy::KEY = "AMovingEnemy";
void AMovingEnemy::Die() {
	Delete(AMovingEnemy::KEY);
	AKDYGameModeBase::instance->MainUI()->RefreshOrange();
	Super::Die();
}
