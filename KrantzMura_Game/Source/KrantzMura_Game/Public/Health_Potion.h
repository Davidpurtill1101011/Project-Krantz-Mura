// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <KrantzMura_Game/Gillie.h>
#include "KrantzMura_Game/Item.h"
#include "Health_Potion.generated.h"


class AGillie;
UCLASS()
class KRANTZMURA_GAME_API AHealth_Potion : public AItem
{
	GENERATED_BODY()
	
public:
	AHealth_Potion();

protected:
	UPROPERTY(EditAnywhere)
		float HealthPoints;

public:
	virtual void Use(AGillie* Character) override;

};
