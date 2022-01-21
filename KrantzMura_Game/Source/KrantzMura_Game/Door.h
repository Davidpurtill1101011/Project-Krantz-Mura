// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class UAnimationAsset;

UCLASS()
class KRANTZMURA_GAME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Door")
		class USkeletalMeshComponent* DoorMesh;// creating a property to make a mesh for the door and be able to assign it from anywhere

	UPROPERTY(EditAnywhere, Category = "Door")
		UAnimationAsset* OpenAnimation;// property for an open door animation

	UPROPERTY(EditAnywhere, Category = "Door")
		UAnimationAsset* CloseAnimation;// property for an close door animation

	//Control boolean for the door 
	bool isOpen;
public:
	// methods definded here and implemented over in the .CPP file.
	void ToggleDoor();
};
