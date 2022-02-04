// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include <Components/InputComponent.h>
#include <GameFramework/Controller.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "Components/CapsuleComponent.h"
#include "Door.h"
#include "Gillie.generated.h"

UCLASS()
class KRANTZMURA_GAME_API AGillie : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGillie();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Camera")// making the camera boom
		USpringArmComponent* CameraBoom; // * means that it is a type of SpringArm and the U means it will be picked up by GB collection..

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Camera")// camera Follows the player
		UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Character Movement: Walking")
		float SprintSpeedMultiplier;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Character Movement: Walking")
		float WalkSpeed;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Animation")
		class UAnimMontage* FightingMontage; // this lets bid to the blueprint via C++ code

	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartCrouching();

	void Sprint();
	void StopSprinting();

	void Walking();
	void StopWalking();

	void Interact();

	// functions for fighting
	void StartAttack();
	void StopAttack();

	bool isDead;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
