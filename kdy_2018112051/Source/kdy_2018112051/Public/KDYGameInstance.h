// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KDYGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class KDY_2018112051_API UKDYGameInstance : public UGameInstance {
	GENERATED_BODY()
	int stage;

	static UKDYGameInstance* instance;

public:
	static UKDYGameInstance* Instance();

	virtual void Init() override;

	int GetStage();
	void StageClear();
	void StageReset();
};
