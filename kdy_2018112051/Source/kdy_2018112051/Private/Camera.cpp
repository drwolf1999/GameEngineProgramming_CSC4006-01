// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"

#include "Camera/CameraComponent.h"

// Sets default values
ACamera::ACamera() {
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    RootComponent = camera;
}

// Called when the game starts or when spawned
void ACamera::BeginPlay() {
    Super::BeginPlay();
}

// Called every frame
void ACamera::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    if (Target) {
        FVector DesiredLocation = Target->GetActorLocation() + Offset;
        SetActorLocation(DesiredLocation);
    } else {
        Target = GetWorld()->GetFirstPlayerController()->GetPawn();

        if (Target) GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
    }
}
