// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopKeeper.h"
#include <Components/SkeletalMeshComponent.h>
#include "KrantzMura_Game/Item.h"
#include <Kismet/GameplayStatics.h>
#include <KrantzMura_Game/Gillie.h>
#include "..\Public\ShopKeeper.h"

// Sets default values
AShopKeeper::AShopKeeper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ShopKeeperMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = ShopKeeperMesh;

}



// Called when the game starts or when spawned
void AShopKeeper::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShopKeeper::Shop_Items()
{
	if (AGillie* Character = Cast<AGillie>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))) 
	{
		Character->OpenShop(this,ShopKeeperItems);
	}
}

void AShopKeeper::Interact(AGillie* Character)
{
	if (Character) {
		Character->OpenShop(this,ShopKeeperItems);
	}
}

void AShopKeeper::ItemTransfer(TSubclassOf<AItem> ItemSubClass)
{
	uint8 Index = 0;
	for (FItem_Information& Item : ShopKeeperItems) {

		if (Item.ItemClass == ItemSubClass) {

			Item.StackCount--;
			if (Item.StackCount <= 0) {

				ShopKeeperItems.RemoveAt(Index);
			}
			break;
		}
		Index++;
	}

	for (FItem_Information& Item : ShopKeeperItems) {
		UE_LOG(LogTemp, Warning, TEXT("Stack Count: %d"), Item.StackCount);
	}

	Shop_Items();
}


