// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap/HideTrap.h"

// Sets default values
AHideTrap::AHideTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHideTrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHideTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

