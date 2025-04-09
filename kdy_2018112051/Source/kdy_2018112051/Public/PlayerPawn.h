// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class KDY_2018112051_API APlayerPawn : public APawn {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;

	const static float DefaultMoveSpeed;
	UPROPERTY(EditAnywhere)
	float MoveSpeed;

	// bullet
	UPROPERTY(EditAnywhere)
	class UArrowComponent* FirePosition;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> BulletFactory;

private:
	float h;
	float v;
	void MoveHorizontal(float h);
	void MoveVertical(float v);
};
