// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Patrol_Character.h"
#include <GameFramework/CharacterMovementComponent.h>

// Sets default values
AAI_Patrol_Character::AAI_Patrol_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;// character to turn itself in the direction of the motion(Face the way its wanting to walk)
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);// the speed in which it rotates at on the Y Axis
}

// Called when the game starts or when spawned
void AAI_Patrol_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Patrol_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Patrol_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

