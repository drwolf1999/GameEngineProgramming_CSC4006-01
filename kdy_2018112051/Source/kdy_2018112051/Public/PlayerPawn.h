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

	// bullet
	UPROPERTY(EditAnywhere)
	class UArrowComponent* FirePosition;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> BulletFactory;

private:
	///////////
	/// power
	///////////
	const static float MaxPower;
	float power;
	void GainPower(float p);
	void LosePower(float p);

	///////////
	/// move
	///////////
	const static float DefaultMoveSpeed;
	const static float RunMoveSpeed;
	UPROPERTY(EditAnywhere)
	float speed;
	void MoveTick(float DeltaTime);
	void Walk();
	void Run();

	float h;
	float v;
	void MoveHorizontal(float h);
	void MoveVertical(float v);

	void Fire();
};
