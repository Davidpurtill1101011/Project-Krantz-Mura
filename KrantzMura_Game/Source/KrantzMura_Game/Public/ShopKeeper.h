// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <InteractableInterface.h>
#include <KrantzMura_Game/Structs.h>
#include "ShopKeeper.generated.h"


UCLASS()
class KRANTZMURA_GAME_API AShopKeeper : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShopKeeper();

protected:
	UPROPERTY(EditDefaultsOnly)
		class USkeletalMeshComponent* ShopKeeperMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory System")
		TArray<FItem_Information> ShopKeeperItems;

	UFUNCTION()
		void Shop_Items();

	virtual void BeginPlay() override;

public:
	virtual void Interact(class AGillie* Character) override;

	virtual void ItemTransfer(TSubclassOf<AItem> ItemSubClass);

};
