// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/StopEnemy.h"

#include "UI/UIManager.h"
#include "UI/MainWidget.h"
#include <typeinfo>

// Sets default values
AStopEnemy::AStopEnemy() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AStopEnemy::BeginPlay() {
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
		if (AUIManager::Instance() && AUIManager::Instance()->IsInitialized()) {
			AEnemy::Create(AStopEnemy::KEY);
			this->power = 10;
			AUIManager::Instance()->MainUI()->RefreshYellow();
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

const std::string AStopEnemy::KEY = "AStopEnemy";
void AStopEnemy::Die() {
	Delete(AStopEnemy::KEY);
	AUIManager::Instance()->MainUI()->RefreshYellow();
	Super::Die();
}
