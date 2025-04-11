// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera.generated.h"

UCLASS()
class KDY_2018112051_API ACamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	AActor* Target;

	UPROPERTY(EditAnywhere)
	FVector Offset = FVector(-1000.f, 0.f, 0.f);

private:
	UPROPERTY()
	class UCameraComponent* camera;
};
