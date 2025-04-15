// Fill out your copyright notice in the Description page of Project Settings.


#include "kdy_2018112051/Public/PlayerPawn.h"

#include "Bullet.h"
#include "UI/UIManager.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UI/MainWidget.h"

const int APlayerPawn::MaxHp = 100;
const int APlayerPawn::MaxPower = 100;
const int APlayerPawn::MaxBullet = 30;
const int APlayerPawn::MaxSkill = 1;
const float APlayerPawn::DefaultMoveSpeed = 500.f;
const float APlayerPawn::RunMoveSpeed = 1000.f;

// Sets default values
APlayerPawn::APlayerPawn() {
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // BoxComponent
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    SetRootComponent(BoxComponent);
    BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));

    BoxComponent->SetCollisionProfileName(TEXT("Player"));

    // MeshComponent
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(BoxComponent);

    // ArrowComponent
    FirePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
    FirePosition->SetupAttachment(BoxComponent);
    // MeshComponent
    SubMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SubMeshComponent"));
    SubMeshComponent->SetupAttachment(FirePosition);

    // Default Variable Setting
    hp = MaxHp;
    power = MaxPower;
    bullet = MaxBullet;
    skill = MaxSkill;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay() {
    Super::BeginPlay();

    // GameMode 초기화될 때까지 기다리기
    GetWorld()->GetTimerManager().SetTimerForNextTick([this]() {
        if (AUIManager::Instance() && AUIManager::Instance()->IsInitialized()) {
        	isWalk = true;
        	isHide = false;
            AUIManager::Instance()->MainUI()->RefreshHP(hp);
            AUIManager::Instance()->MainUI()->RefreshPower(power);
            AUIManager::Instance()->MainUI()->RefreshBullet(bullet);
            AUIManager::Instance()->MainUI()->RefreshSkill(skill);
        } else {
            // 아직 초기화 안 됐으면 한 틱 뒤에 다시 시도
            GetWorld()->GetTimerManager().SetTimerForNextTick([this]() { this->BeginPlay(); });
        }
    });
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    MoveTick(h, v, DeltaTime);
    RotationTick(h, v, DeltaTime);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawn::MoveHorizontal);
    PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawn::MoveVertical);
	
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayerPawn::Run);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayerPawn::Walk);

    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerPawn::Fire);
	PlayerInputComponent->BindAction("Skill", IE_Pressed, this, &APlayerPawn::SKill);
}

///////////
/// HP
///////////
void APlayerPawn::Heal(int _h) {
    hp = hp + _h > MaxHp ? MaxHp : hp + _h;

    AUIManager::Instance()->MainUI()->RefreshHP(hp);
}

void APlayerPawn::GetDamage(int _h) {
    hp = hp - _h < 0 ? 0 : hp - _h;

	UE_LOG(LogTemp, Display, TEXT("PlayerGetDamage: Before"))
    AUIManager::Instance()->MainUI()->RefreshHP(hp);

	UE_LOG(LogTemp, Display, TEXT("PlayerGetDamage: AfterRefresh"))
    if (hp == 0) {
	    AUIManager::Instance()->OpenGameOverUI();
    	Destroy();
    }
}


///////////
/// power
///////////
void APlayerPawn::GainPower(int p) {
    // check available
    power = power + p > MaxPower ? MaxPower : power + p;
    AUIManager::Instance()->MainUI()->RefreshPower(power);
}

void APlayerPawn::LosePower(int p) {
    // check available
    power = power - p < 0 ? 0 : power - p;
    AUIManager::Instance()->MainUI()->RefreshPower(power);
}

///////////
/// move
///////////
void APlayerPawn::MoveTick(float _h, float _v, float DeltaTime) {
    auto dir = FVector(0, _h, _v);
    if (dir.IsNearlyZero()) { return; }

    dir.Normalize();

	float speed = (isWalk ? DefaultMoveSpeed : RunMoveSpeed) * 1;
    FVector newLoc = GetActorLocation() + speed * dir * DeltaTime;
    FHitResult hit;
    if (!SetActorLocation(newLoc, true, &hit) && hit.IsValidBlockingHit()) {
        if (_h * _h * _v * _v > 0.0001) {
            MoveTick(_h, 0, DeltaTime);
            MoveTick(0, _v, DeltaTime);
        }
    }
}

void APlayerPawn::RotationTick(float _h, float _v, float DeltaTime) {
    auto dir = FVector(0, _h, _v);
    if (dir.IsNearlyZero()) { return; }

    dir.Normalize();
    float pitchRad = FMath::Atan2(dir.Y, dir.Z);        // ZY 평면 각도
    float pitchDeg = FMath::RadiansToDegrees(pitchRad); // Degree 변환
    pitchDeg = FMath::Fmod(pitchDeg + 360.f, 360.f);    // 0~360 범위로 정리

    SetActorRotation(FRotator(0, 0, pitchDeg)); // X(Pitch)만 회전
}


void APlayerPawn::MoveHorizontal(float value) { this->h = value; }

void APlayerPawn::MoveVertical(float value) { this->v = value; }

void APlayerPawn::Walk() { this->isWalk = true; }

void APlayerPawn::Run() { this->isWalk = false; }

void APlayerPawn::EarnBullet(int _bullet) {
    this->bullet += _bullet;
    if (this->bullet > APlayerPawn::MaxBullet) { this->bullet = APlayerPawn::MaxBullet; }

    AUIManager::Instance()->MainUI()->RefreshBullet(this->bullet);
}

void APlayerPawn::Fire() {
    if (this->bullet == 0) return;
    this->bullet--;
    ABullet *b = GetWorld()->SpawnActor<ABullet>(BulletFactory, FirePosition->GetComponentLocation(),
                                                 FirePosition->GetComponentRotation());
    AUIManager::Instance()->MainUI()->RefreshBullet(this->bullet);
}

void APlayerPawn::SKill() {
	if (skill <= 0) {
		return;
	}
    this->skill--;
    //
    AUIManager::Instance()->MainUI()->RefreshSkill(skill);
}