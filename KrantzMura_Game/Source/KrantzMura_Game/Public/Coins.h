#pragma once

#include "CoreMinimal.h"
#include "KrantzMura_Game/Item.h"
#include "Coins.generated.h"

/**
 * 
 */
class AGillie;
UCLASS()
class KRANTZMURA_GAME_API ACoins : public AItem
{
	GENERATED_BODY()
public:
	ACoins();
	virtual void Use(AGillie* Character, bool IsInShop = false) override;
	
};
