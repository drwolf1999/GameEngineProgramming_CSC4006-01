// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerPawn.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()

class KDY_2018112051_API AItem : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnItemOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	                   UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
	                   const FHitResult& sweepResult);

	virtual void OnPlayerOverlap(APlayerPawn* player);
};
