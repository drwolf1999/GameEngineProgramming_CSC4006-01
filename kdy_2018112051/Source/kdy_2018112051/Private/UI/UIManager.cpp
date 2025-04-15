// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UIManager.h"

#include "Game.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AUIManager::AUIManager() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUIManager::BeginPlay() {
	Super::BeginPlay();

	if (MainWidget) {
		mainUI = CreateWidget<UMainWidget>(GetWorld(), MainWidget);
		if (mainUI) {
			mainUI->AddToViewport();
		}
	}
	if (GameOverUI) {
		gameOverUI = CreateWidget<UGameOverUI>(GetWorld(), GameOverUI);
		if (gameOverUI) {
			gameOverUI->AddToViewport();
			gameOverUI->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	if (WinUI) {
		winUI = CreateWidget<UWinUI>(GetWorld(), WinUI);
		if (winUI) {
			winUI->AddToViewport();
			winUI->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	instance = this;
	isInitialized = true;
}

// Called every frame
void AUIManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

bool AUIManager::IsInitialized() {
	return isInitialized;
}

void AUIManager::OpenGameOverUI() {
	AGame::Instance()->BlockInput(gameOverUI->TakeWidget());
	gameOverUI->SetVisibility(ESlateVisibility::Visible);
}

void AUIManager::OpenWinUI() {
	AGame::Instance()->BlockInput(winUI->TakeWidget());
	winUI->SetVisibility(ESlateVisibility::Visible);
}


AUIManager* AUIManager::instance = nullptr;

AUIManager* AUIManager::Instance() {
	return instance;
}

UMainWidget* AUIManager::MainUI() {
	return mainUI;
}