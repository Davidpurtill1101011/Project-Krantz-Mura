// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include <Components/StaticMeshComponent.h>
#include <KrantzMura_Game/Gillie.h>

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;

	ItemData.ItemClass = StaticClass();
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Interact(class AGillie* Character)
{
	if (Character) { // this checks to the see if the player is valid
		// then if the player is valid then add it to the player inventory
		Character->AddInventoryItem(ItemData);
		// and when added to the inventory remove it from the world
		Destroy();
	}
	
}

void AItem::Use(AGillie* Character)
{
	UE_LOG(LogTemp, Warning, TEXT("USING ITEM: %s"), *GetName());
}



