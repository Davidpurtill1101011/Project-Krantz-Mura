// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include <KrantzMura_Game/Gillie.h>

AFood::AFood() 
{
	HungerPoints = 20.0f;
	ItemData.ItemClass = StaticClass();
}

void AFood::Use(AGillie* Character)
{
	if (Character) {
		UE_LOG(LogTemp, Warning, TEXT("FOOD"));
		Character->RemoveHunger(HungerPoints);
	}

}
