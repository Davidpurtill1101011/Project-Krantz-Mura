// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include <KrantzMura_Game/Gillie.h>

AFood::AFood() 
{
	FoodValue = 30.0f;
	ItemData.ItemClass = StaticClass();
}

void AFood::Use(AGillie* Character)
{
	if (Character) {
		Character->RemoveHunger(FoodValue);
	}
}
