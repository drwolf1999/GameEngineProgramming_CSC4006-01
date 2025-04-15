// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget.h"

#include "PlayerPawn.h"
#include "Components/TextBlock.h"
#include "Enemy/Enemy.h"
#include "Enemy/FollowEnemy.h"
#include "Enemy/MovingEnemy.h"
#include "Enemy/SpecialEnemy.h"
#include "Enemy/StopEnemy.h"

FText UMainWidget::EnemyText(std::string t) {
	return FText::FromString(FString::Printf(TEXT("%d / %d"), AEnemy::GetCount(t), AEnemy::GetTotalCount(t)));
}

FText UMainWidget::PlayerText(int v, int max) {
	return FText::FromString(FString::Printf(TEXT("%d / %d"), v, max));
}

void UMainWidget::RefreshRed() {
	Red->Data->SetText(EnemyText(AFollowEnemy::KEY));
}

void UMainWidget::RefreshOrange() {
	Orange->Data->SetText(EnemyText(AMovingEnemy::KEY));
}

void UMainWidget::RefreshYellow() {
	Yellow->Data->SetText(EnemyText(AStopEnemy::KEY));
}

void UMainWidget::RefreshCustom() {
	Custom->Data->SetText(EnemyText(ASpecialEnemy::KEY));
}

void UMainWidget::RefreshHP(int hp) {
	HP->Data->SetText(PlayerText(hp, APlayerPawn::MaxHp));
}

void UMainWidget::RefreshPower(int power) {
	Power->Data->SetText(PlayerText(power, APlayerPawn::MaxPower));
}

void UMainWidget::RefreshBullet(int bullet) {
	Bullet->Data->SetText(PlayerText(bullet, APlayerPawn::MaxBullet));
}

void UMainWidget::RefreshSkill(int skill) {
	Skill->Data->SetText(PlayerText(skill, APlayerPawn::MaxSkill));
}

void UMainWidget::NativeConstruct() {
	Super::NativeConstruct();
}


