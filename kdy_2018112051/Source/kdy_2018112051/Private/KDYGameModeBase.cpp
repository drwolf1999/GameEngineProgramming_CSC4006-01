// Fill out your copyright notice in the Description page of Project Settings.


#include "kdy_2018112051/Public/KDYGameModeBase.h"

#include "Blueprint/UserWidget.h"
#include "Enemy/Enemy.h"
#include "UI/MainWidget.h"

AKDYGameModeBase* AKDYGameModeBase::instance = nullptr;

class UMainWidget*& AKDYGameModeBase::MainUI() {
	return mainUI;
}

void AKDYGameModeBase::BeginPlay() {
	Super::BeginPlay();

    AEnemy::Reload();

	if (MainWidget) {
		mainUI = CreateWidget<UMainWidget>(GetWorld(), MainWidget);
		if (mainUI) {
			mainUI->Init();
			mainUI->AddToViewport();
		}
	}

	instance = this;
	IsInitialized = true;
}
