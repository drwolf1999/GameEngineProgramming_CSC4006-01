// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item/Item.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerItem.generated.h"

UCLASS()
class KDY_2018112051_API APowerItem : public AItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
