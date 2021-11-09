// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
// adding libraries
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/InputComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include <GameFramework/Controller.h>
#include <GameFramework/SpringArmComponent.h>

#include <Blueprint/UserWidget.h>
// if any includes are after the line below they wont be complied 
// or used in the object/class
#include "Gillie.generated.h"

UCLASS()
class KRANTZMURA_GAME_API AGillie : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGillie(); // constructor

	// visible in the Unreal Engine IDE
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoom; // * is another way of using pointers
	// visible in the Unreal Engine IDE
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;

	// Creating player movement.
	void MoveForward(float Axis);
	void MoveRight(float Axis);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
