// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/SpecialItem.h"

void ASpecialItem::OnPlayerOverlap(APlayerPawn* player) {
	if (player) {
		player->godMode += 5.f;
		Destroy();
	}
}
