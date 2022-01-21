// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include <Components/SkeletalMeshComponent.h>

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	DoorMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	RootComponent = DoorMesh;

	isOpen = false;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoor::ToggleDoor()
{
	if (isOpen) {// checking to see if the door is open or not
		isOpen = false;// if it is turn it to fales
		if (CloseAnimation) {
			DoorMesh->PlayAnimation(CloseAnimation, false);
			isOpen = false;
		}
	}
	else {
		if (OpenAnimation) {
			DoorMesh->PlayAnimation(OpenAnimation, false);
			isOpen = true;
		}
	}
	// this makes the door to false if true and true if false;
	//isOpen = !isOpen;

}

