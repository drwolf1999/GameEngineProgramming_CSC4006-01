// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/SpecialEnemy.h"

#include "UI/UIManager.h"
#include <typeinfo>

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UI/MainWidget.h"

// Sets default values
ASpecialEnemy::ASpecialEnemy() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SubMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SubMeshComponent"));
	SubMesh->SetupAttachment(SphereComponent);
	SubMesh->SetRelativeLocation(FVector(12.5f, 0.f, -0.f));
	SubMesh->SetWorldScale3D(FVector(2.f, 2.f, .3f));
}

// Called when the game starts or when spawned
void ASpecialEnemy::BeginPlay() {
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
		if (AUIManager::Instance() && AUIManager::Instance()->IsInitialized()) {
			Create(KEY);
			this->hp = 50;
			AUIManager::Instance()->MainUI()->RefreshCustom();
		} else {
			// 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
			GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
		}
	});

	GetWorld()->GetTimerManager().SetTimer(
		VisibilityTickHandle,
		this,
		&ASpecialEnemy::VisibilityTick,
		1.0f, true
	);
}

// Called every frame
void ASpecialEnemy::Tick(float DeltaTime) {
	if (!player) {
		APawn* p = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		player = Cast<APlayerPawn>(p);
	}
	Super::Tick(DeltaTime);
	Deal();
}

void ASpecialEnemy::MoveTick(float DeltaTime) {
	if (!player || player->isHide) {
		return;
	}

	this->dir = player->GetActorLocation() - GetActorLocation();
	this->dir.Normalize();

	FVector newLoc = GetActorLocation() + this->MoveSpeed * dir * DeltaTime * (this->isBoost ? 2.f : 1.f);
	SetActorLocation(newLoc, true);
}

void ASpecialEnemy::VisibilityTick() {
	VisibilityTickCounter++;

	if (bVisible && VisibilityTickCounter >= 4) {
		bVisible = false;
		SetActorHiddenInGame(true);
	} else if (!bVisible && VisibilityTickCounter >= 5) {
		bVisible = true;
		SetActorHiddenInGame(false);
		VisibilityTickCounter = 0;
	}
}

void ASpecialEnemy::Deal() {
	if (!player || player->isHide) {
		return;
	}

	const float Distance = FVector::Dist(GetActorLocation(), player->GetActorLocation());

	if (Distance <= 150.0f) {
		float currentTime = GetWorld()->GetTimeSeconds();
		if (currentTime - LastDamageTime >= DamageInterval) {
			player->GetDamage(10);
			LastDamageTime = currentTime;
		}
	}
}

const std::string ASpecialEnemy::KEY = "ASpecialEnemy";

void ASpecialEnemy::Die() {
	Delete(KEY);
	AUIManager::Instance()->MainUI()->RefreshCustom();
	Super::Die();
}
