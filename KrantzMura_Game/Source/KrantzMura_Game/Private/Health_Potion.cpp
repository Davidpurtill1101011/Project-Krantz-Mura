// Fill out your copyright notice in the Description page of Project Settings.


#include "Health_Potion.h"

AHealth_Potion::AHealth_Potion() 
{
	HealthPoints = 10.0f;
	ItemData.ItemClass = StaticClass();
}

void AHealth_Potion::Use(AGillie* Character)
{
	if (Character) {
		Character->AddHealth(HealthPoints);
	}
}
