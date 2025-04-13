// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget.h"

#include "PlayerPawn.h"
#include "Components/TextBlock.h"
#include "Enemy/Enemy.h"
#include "Enemy/FollowEnemy.h"
#include "Enemy/MovingEnemy.h"
#include "Enemy/SpecialEnemy.h"
#include "Enemy/StopEnemy.h"

FText UMainWidget::EnemyText(std::type_index t) {
	return FText::FromString(FString::Printf(TEXT("%d / %d"), AEnemy::GetCount(t), AEnemy::GetTotalCount(t)));
}

FText UMainWidget::PlayerText(int v, int max) {
	return FText::FromString(FString::Printf(TEXT("%d / %d"), v, max));
}

void UMainWidget::RefreshRed() {
	Red->Data->SetText(EnemyText(typeid(AFollowEnemy)));
}

void UMainWidget::RefreshOrange() {
	Orange->Data->SetText(EnemyText(typeid(AMovingEnemy)));
}

void UMainWidget::RefreshYellow() {
	Yellow->Data->SetText(EnemyText(typeid(AStopEnemy)));
}

void UMainWidget::RefreshCustom() {
	Custom->Data->SetText(EnemyText(typeid(ASpecialEnemy)));
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

void UMainWidget::Init() {
	USlot* slot[] = {
		Red, Orange, Yellow, Custom,
		HP, Power, Bullet, Skill
	};

	for (USlot* s : slot) {
		s->Init();
	}
}


