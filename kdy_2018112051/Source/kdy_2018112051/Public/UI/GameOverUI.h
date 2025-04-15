// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KDYGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "GameOverUI.generated.h"

/**
 * 
 */
UCLASS()
class KDY_2018112051_API UGameOverUI : public UUserWidget {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* RestartButton;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* QuitButton;

	UFUNCTION()
	void Restart();

	UFUNCTION()
	void Quit();

public:
	virtual void NativeConstruct() override;
};
