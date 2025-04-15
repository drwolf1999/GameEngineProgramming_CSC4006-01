// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Slot.h"

#include "Components/TextBlock.h"

void USlot::NativeConstruct() {
	Super::NativeConstruct();
	if (Text) {
		Text->SetText(FText::FromString(TextValue));
	    Text->SetColorAndOpacity(FSlateColor(Color));
	}
}
