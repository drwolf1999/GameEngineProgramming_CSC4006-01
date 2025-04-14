// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/FollowEnemy.h"

#include "KDYGameModeBase.h"
#include "UI/MainWidget.h"
#include <typeinfo>

// Sets default values
AFollowEnemy::AFollowEnemy() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
}

// Called when the game starts or when spawned
void AFollowEnemy::BeginPlay() {
    Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
		if (AKDYGameModeBase::instance && AKDYGameModeBase::instance->IsInitialized) {
			AEnemy::Create(AFollowEnemy::KEY);
			this->power = 30;
			AKDYGameModeBase::instance->MainUI()->RefreshRed();
		} /*else {
			// 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
			GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
		}*/
	});
}

// Called every frame
void AFollowEnemy::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

void AFollowEnemy::MoveTick(float DeltaTime) {
    AEnemy::MoveTick(DeltaTime);
}

const std::string AFollowEnemy::KEY = "AFollowEnemy";

void AFollowEnemy::Die() {
	Delete(AFollowEnemy::KEY);
	AKDYGameModeBase::instance->MainUI()->RefreshRed();
	Super::Die();
}
