// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/MainWidget.h"
#include "UI/WinUI.h"
#include "UI/GameOverUI.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIManager.generated.h"

UCLASS()
class KDY_2018112051_API AUIManager : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainWidget> MainWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameOverUI> GameOverUI;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UWinUI> WinUI;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsInitialized();

	void OpenGameOverUI();
	void OpenWinUI();

	static AUIManager* Instance();
	UMainWidget* MainUI();

private:
	static AUIManager* instance;

	class UWinUI* winUI;
	class UGameOverUI* gameOverUI;
	class UMainWidget* mainUI;

	bool isInitialized;

	APlayerController* _pc;
	APlayerController* PC();
};
