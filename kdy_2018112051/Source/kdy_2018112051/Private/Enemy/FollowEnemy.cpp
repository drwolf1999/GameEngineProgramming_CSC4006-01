// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/FollowEnemy.h"

#include "UI/UIManager.h"
#include "UI/MainWidget.h"
#include <typeinfo>

#include "Kismet/GameplayStatics.h"

// Sets default values
AFollowEnemy::AFollowEnemy() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
}

// Called when the game starts or when spawned
void AFollowEnemy::BeginPlay() {
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
		if (AUIManager::Instance() && AUIManager::Instance()->IsInitialized()) {
			Create(KEY);
			this->hp = 30;
			AUIManager::Instance()->MainUI()->RefreshRed();
		} else {
			// 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
			GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
		}
	});
}

// Called every frame
void AFollowEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AFollowEnemy::MoveTick(float DeltaTime) {
	APawn* player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	APlayerPawn* playerPawn = Cast<APlayerPawn>(player);
	if (!player || !playerPawn || playerPawn->isHide) {
		return;
	}

	this->dir = player->GetActorLocation() - GetActorLocation();
	this->dir.Normalize();

	FVector newLoc = GetActorLocation() + this->MoveSpeed * dir * DeltaTime * (this->isBoost ? 2.f : 1.f);
	SetActorLocation(newLoc, true);
}

void AFollowEnemy::OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                                  UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                                  const FHitResult& sweepResult) {
	// Super::OnEnemyOverlap(overlappedComponent, otherActor, otherComponent, otherBodyIndex, bFromSweep, sweepResult);
}

void AFollowEnemy::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                int32 OtherBodyIndex) {
	// Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}

const std::string AFollowEnemy::KEY = "AFollowEnemy";

void AFollowEnemy::Die() {
	Delete(KEY);
	AUIManager::Instance()->MainUI()->RefreshRed();
	Super::Die();
}
