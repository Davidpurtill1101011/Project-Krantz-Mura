// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Guard_Character.h"
#include <GameFramework/CharacterMovementComponent.h>

// Sets default values
AAI_Guard_Character::AAI_Guard_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// these two definitions let the charanter move and turn in the derection it wants to move
	GetCharacterMovement()->bOrientRotationToMovement = true;// movement
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);//direction / turn movent on the y axis
}

// Called when the game starts or when spawned
void AAI_Guard_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Guard_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Guard_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

