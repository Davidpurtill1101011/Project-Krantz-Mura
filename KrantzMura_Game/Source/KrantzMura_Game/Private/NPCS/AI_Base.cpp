// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCS/AI_Base.h"
#include <GameFramework/CharacterMovementComponent.h>

// Sets default values
AAI_Base::AAI_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;// lets the character to turn in the way it is walking
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);// turn rate of the AI
}

// Called when the game starts or when spawned
void AAI_Base::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AAI_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}