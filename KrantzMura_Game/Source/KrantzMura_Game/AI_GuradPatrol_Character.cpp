// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_GuradPatrol_Character.h"

// Sets default values
AAI_GuradPatrol_Character::AAI_GuradPatrol_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_GuradPatrol_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_GuradPatrol_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_GuradPatrol_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

