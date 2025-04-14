// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include "CoreMinimal.h"
#include "Slot.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class KDY_2018112051_API UMainWidget : public UUserWidget {
	GENERATED_BODY()

	//////////////
	/// LEFT
	//////////////
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* Red;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* Orange;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* Yellow;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* Custom;

	FText EnemyText(std::string);

	//////////////
	/// RIGHT
	//////////////
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* HP;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* Power;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* Bullet;

	UPROPERTY(EditAnywhere, meta=(BindWidget))
	USlot* Skill;

	FText PlayerText(int, int);

public:
	//////////////
	/// LEFT
	//////////////
	void RefreshRed();
	void RefreshOrange();
	void RefreshYellow();
	void RefreshCustom();

	//////////////
	/// RIGHT
	//////////////
	void RefreshHP(int hp);
	void RefreshPower(int power);
	void RefreshBullet(int bullet);
	void RefreshSkill(int skill);
	
	void Init();
};
