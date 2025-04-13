// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/StopEnemy.h"

#include "KDYGameModeBase.h"
#include "UI/MainWidget.h"

// Sets default values
AStopEnemy::AStopEnemy() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AStopEnemy::BeginPlay() {
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
		if (AKDYGameModeBase::instance && AKDYGameModeBase::instance->IsInitialized) {
			AEnemy::Create(typeid(AStopEnemy));
			this->power = 10;
			AKDYGameModeBase::instance->MainUI()->RefreshYellow();
		} else {
			// 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
			GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
		}
	});
}

// Called every frame
void AStopEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AStopEnemy::MoveTick(float DeltaTime) {
}

void AStopEnemy::Die() {
	Delete(typeid(AStopEnemy));
	AKDYGameModeBase::instance->MainUI()->RefreshYellow();
	Super::Die();
}
