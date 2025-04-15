// Fill out your copyright notice in the Description page of Project Settings.


#include "KDYGameInstance.h"

UKDYGameInstance* UKDYGameInstance::instance = nullptr;
UKDYGameInstance* UKDYGameInstance::Instance() {
	return instance;
}

void UKDYGameInstance::Init() {
	Super::Init();
	StageReset();
	instance = this;
}

int UKDYGameInstance::GetStage() {
	return stage;
}

void UKDYGameInstance::StageClear() {
	stage++;
}

void UKDYGameInstance::StageReset() {
	stage = 0;
}
