// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "SpecialItem.generated.h"

/**
 * 
 */
UCLASS()
class KDY_2018112051_API ASpecialItem : public AItem {
	GENERATED_BODY()

	virtual void OnPlayerOverlap(APlayerPawn* player) override;
};
