// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"

#include "EngineUtils.h"
#include "PlayerPawn.h"
#include "Components/SphereComponent.h"
#include "UI/UIManager.h"

// Sets default values
AEnemy::AEnemy() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);
	SphereComponent->SetSphereRadius(50.f);

	SphereComponent->SetCollisionProfileName(TEXT("Enemy"));

	// MeshComponent
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(SphereComponent);
	MeshComponent->SetRelativeLocation(FVector(0, 0, -50.f));
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay() {
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnEnemyOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AEnemy::OnOverlapEnd);
}

// Called every frame
void AEnemy::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	MoveTick(DeltaTime);
}

void AEnemy::MoveTick(float DeltaTime) {
}

void AEnemy::GetDamage(int damage) {
	hp -= damage;

	if (hp <= 0) {
		Die();
	}
}

void AEnemy::OnEnemyOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor,
                            UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep,
                            const FHitResult& sweepResult) {
	APlayerPawn* player = Cast<APlayerPawn>(otherActor);
	if (player) {
		overlapTime = 0;
		overlappedPlayer = player;
		player->GetDamage(10);
	}
}

void AEnemy::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                          int32 OtherBodyIndex) {
	APlayerPawn* player = Cast<APlayerPawn>(OtherActor);
	if (player) {
		overlappedPlayer = nullptr;
		overlapTime = 0;
	}
}

void AEnemy::Die() {
	Destroy();
}

void AEnemy::Reload() {
	TypeCount.clear();
	TypeTotalCount.clear();
}


std::unordered_map<std::string, int> AEnemy::TypeCount = std::unordered_map<std::string, int>();
std::unordered_map<std::string, int> AEnemy::TypeTotalCount = std::unordered_map<std::string, int>();

int AEnemy::GetTotalCount(std::string t) {
	return TypeTotalCount[t];
}

int AEnemy::GetCount(std::string t) {
	return TypeCount[t];
}

void AEnemy::Create(std::string t) {
	TypeCount[t]++;
	TypeTotalCount[t]++;
}

void AEnemy::Delete(std::string t) {
	TypeCount[t]--;

	int c = 0;
	for (auto it : TypeCount) {
		c += it.second;
	}
	if (c == 0) {
		AUIManager::Instance()->OpenWinUI();
	}
}
