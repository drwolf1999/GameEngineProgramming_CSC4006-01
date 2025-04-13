// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "KDYGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class KDY_2018112051_API AKDYGameModeBase : public AGameModeBase {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainWidget> MainWidget;

	class UMainWidget*& MainUI();
	static AKDYGameModeBase* instance;
	bool IsInitialized = false;

protected:
	virtual void BeginPlay() override;

private:
	class UMainWidget* mainUI;
};
