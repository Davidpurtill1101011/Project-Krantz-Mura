// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPotion.h"
#include <KrantzMura_Game/Gillie.h>

AHealthPotion::AHealthPotion()
{
	HealthPoints = 10.0f;
	ItemData.ItemClass = StaticClass();
}

void AHealthPotion::Use(AGillie* Character)
{
	if (Character) {
		Character->AddHealth(HealthPoints);
	}
}
