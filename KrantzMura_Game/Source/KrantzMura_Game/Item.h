// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <KrantzMura_Game/Public/InteractableInterface.h>
#include "Structs.h"
#include "Item.generated.h"


UCLASS()
class KRANTZMURA_GAME_API AItem : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Intventory Item")
		class UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere, Category = "Intventory Item")
		FItem_Information ItemData;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

public:
	virtual void Interact(class AGillie* Character) override;

	FItem_Information GetItemData() const { return ItemData; }

	virtual void Use(AGillie* Character, bool IsInShop = false) override;

};
