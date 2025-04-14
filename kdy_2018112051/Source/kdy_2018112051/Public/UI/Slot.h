// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Slot.generated.h"

/**
 * 
 */
UCLASS()
class KDY_2018112051_API USlot : public UUserWidget {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	class UTextBlock* Text;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	class UTextBlock* Data;

	UPROPERTY(EditAnywhere)
	FString TextValue;

    // UPROPERTY(EditAnywhere)
    // FLinearColor Color;

	void Init();
};
