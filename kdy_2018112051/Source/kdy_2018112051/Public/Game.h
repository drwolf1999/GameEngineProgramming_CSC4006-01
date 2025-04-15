// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game.generated.h"

UCLASS()
class KDY_2018112051_API AGame : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AllowInput();
	void BlockInput(TSharedRef<SWidget> widget);

	static AGame* Instance();

private:
	static AGame* instance; 
	void Init();
};
