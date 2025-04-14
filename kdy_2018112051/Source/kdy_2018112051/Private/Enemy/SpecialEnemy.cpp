// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SpecialEnemy.h"

#include "KDYGameModeBase.h"
#include <typeinfo>
#include "UI/MainWidget.h"

// Sets default values
ASpecialEnemy::ASpecialEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpecialEnemy::BeginPlay()
{
	Super::BeginPlay();
    
	GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
	if (AKDYGameModeBase::instance && AKDYGameModeBase::instance->IsInitialized) {
		AEnemy::Create(ASpecialEnemy::KEY);
		this->power = 50;
		AKDYGameModeBase::instance->MainUI()->RefreshCustom();
	}/* else {
		// 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
		GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
	}*/
});
}

// Called every frame
void ASpecialEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpecialEnemy::MoveTick(float DeltaTime) {
    AEnemy::MoveTick(DeltaTime);
}

const std::string ASpecialEnemy::KEY = "ASpecialEnemy";
void ASpecialEnemy::Die() {
	Delete(ASpecialEnemy::KEY);
	AKDYGameModeBase::instance->MainUI()->RefreshCustom();
	Super::Die();
}
