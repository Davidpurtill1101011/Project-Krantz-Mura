// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KrantzMura_Game/Item.h"
#include "Food.generated.h"

class AGillie;

UCLASS()
class KRANTZMURA_GAME_API AFood : public AItem
{
	GENERATED_BODY()
public:
	AFood();

protected:
	UPROPERTY(EditAnywhere)
		float FoodValue;

public:
	virtual void Use(AGillie* Character) override;
};
