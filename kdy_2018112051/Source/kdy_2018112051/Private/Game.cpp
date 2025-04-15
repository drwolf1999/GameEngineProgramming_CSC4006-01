// Fill out your copyright notice in the Description page of Project Settings.


#include "Game.h"

#include "Enemy/Enemy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGame::AGame() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Init();
}

// Called when the game starts or when spawned
void AGame::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AGame::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AGame::AllowInput() {
	APlayerController* pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FInputModeGameOnly GameMode;
	pc->SetInputMode(GameMode);
	pc->bShowMouseCursor = false;
}

void AGame::BlockInput(TSharedRef<SWidget> widget) {
	APlayerController* pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(widget); // 포커스 줄 위젯
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	pc->SetInputMode(InputMode);
	pc->bShowMouseCursor = true;
}

AGame* AGame::instance = nullptr;
AGame* AGame::Instance() {
	return instance;
}

void AGame::Init() {
	instance = this;
	AEnemy::Reload();
}
