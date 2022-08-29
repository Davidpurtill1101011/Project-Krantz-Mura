// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <KrantzMura_Game/Item.h>
#include "HealthPotion.generated.h"

class AGillie;
UCLASS()
class KRANTZMURA_GAME_API AHealthPotion : public AItem
{
	GENERATED_BODY()

public:
	AHealthPotion();
protected:
	UPROPERTY(EditAnywhere)
		float HealthPoints;
public:
	virtual void Use(AGillie* Character, bool IsInShop = false) override;
};
