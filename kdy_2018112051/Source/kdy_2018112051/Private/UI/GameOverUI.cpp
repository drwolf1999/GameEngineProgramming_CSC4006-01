// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameOverUI.h"

#include "Game.h"
#include "Kismet/GameplayStatics.h"

void UGameOverUI::NativeConstruct() {
	Super::NativeConstruct();

	RestartButton->OnClicked.AddDynamic(this, &UGameOverUI::Restart);
	QuitButton->OnClicked.AddDynamic(this, &UGameOverUI::Quit);
}

void UGameOverUI::Restart() {
	AGame::Instance()->AllowInput();
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void UGameOverUI::Quit() {
	UKDYGameInstance::Instance()->StageReset();
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}
