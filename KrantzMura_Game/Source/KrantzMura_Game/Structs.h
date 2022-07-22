#pragma once

#include <Structs.generated.h>

USTRUCT(BlueprintType)
struct FItem_Information {
	GENERATED_BODY();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<class AItem> ItemClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UTexture2D* ItemImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ItemCost;

	UPROPERTY(BlueprintReadWrite)
	int32 StackCount = 1;
};