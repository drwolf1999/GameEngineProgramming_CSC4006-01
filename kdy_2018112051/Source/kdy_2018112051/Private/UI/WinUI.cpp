// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WinUI.h"

#include "Game.h"
#include "KDYGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UWinUI::NativeConstruct() {
	Super::NativeConstruct();

	NextButton->OnClicked.AddDynamic(this, &UWinUI::GoNextLevel);
}

void UWinUI::GoNextLevel() {
	UKDYGameInstance::Instance()->StageClear();
	AGame::Instance()->AllowInput();
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
