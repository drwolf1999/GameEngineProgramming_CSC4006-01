// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include "PlayerPawn.h"
#include <string>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class KDY_2018112051_API AEnemy : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 650.f;

	bool isBoost;

	void GetDamage(int damage);

protected:
	int hp;

	virtual void MoveTick(float DeltaTime);

	FVector dir;

	UFUNCTION()
	virtual void OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
	                            UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
	                            const FHitResult& sweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void Die();

	float overlapTime;
	APlayerPawn* overlappedPlayer;

public:
	static void Reload();
	static int GetTotalCount(std::string);
	static int GetCount(std::string);
	static void Create(std::string);
	static void Delete(std::string);

protected:
	static std::unordered_map<std::string, int> TypeTotalCount;
	static std::unordered_map<std::string, int> TypeCount;
};
