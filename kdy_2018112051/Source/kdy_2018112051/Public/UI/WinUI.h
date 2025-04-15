// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "WinUI.generated.h"

/**
 * 
 */
UCLASS()
class KDY_2018112051_API UWinUI : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UButton* NextButton;

	UFUNCTION()
	void GoNextLevel();

public:
	virtual void NativeConstruct() override;
};
